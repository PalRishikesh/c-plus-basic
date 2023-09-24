const AWS = require('aws-sdk');
const mysql = require('mysql');
const TokenUtils = require('/opt/config/tokenUtils');
// const moment = require('moment');
const moment = require('moment-timezone');
const GoalHelper = require('goalHelper');
const CommonAddGoalHelper = require("/opt/config/commonAddGoal");

const sqs = new AWS.SQS({ apiVersion: '2012-11-05' });
const AWSREGION = process.env.AWS_REGION;
const ses = new AWS.SES({ region: AWSREGION });
const { v4: uuidv4 } = require('uuid');
const { version } = require('os');
const { scheduler } = require('timers/promises');

const dbHost = process.env.DBHOST;
const dbPort = process.env.DBPORT;
const dbUser = process.env.DBUSER;
const dbPassword = process.env.DBPASSWORD;
const dbName = process.env.DBNAME;

const baseUrl = process.env.BASEURL;
const queueUrl = process.env.QUEUEURL;
const imageUrl = process.env.IMAGEURL;


let dbConn = mysql.createConnection({
    host: dbHost,
    port: dbPort,
    user: dbUser,
    password: dbPassword,
    database: dbName,
    multipleStatements: true
});

//Db connection responce
dbConn.connect(function (err) {
    if (err) throw err;
    console.log("Connected!");
});

const responseHeaders = {
    'Content-Type': 'application/json'
}

//global declaration
let userId;
let todayDate;
let todayDateTime;
let userEmail;
let link;
let goalExist;
let allExists;
let goalVersion;
let goalList;
let share;
let userIdWithGoal= [];

// const userDeptList = async (requestBody) => {
//     const getUserDetails = await GoalHelper.getUsersDetailByUserId(userId, dbConn);
//     const deptId = getUserDetails[0].dept_id;
//     const userDetails = await GoalHelper.getUsersDetailByUserDepIdAndUserId(userId, deptId, dbConn);

//     let userDetailResponseList = [];
//     let lastName = '';
//     let image = '';

//     for (let index = 0; index < userDetails.length; index++) {

//         const cId = userDetails[index].company_id;
//         const companyDetails = await GoalHelper.getCompanyDetailByCompanyId(userDetails[index].company_id, dbConn);
//         if (userDetails[index].last_name != undefined) {
//             lastName = userDetails[index].last_name;
//         }
//         if (userDetails[index].user_photo == null) {
//             image = `${imageUrl}/assets/uploads/users/${userDetails[index].user_photo}`;
//         }

//         userDetailResponseList.push({
//             "fname": userDetails[index].fname,
//             "lastname": lastName,
//             "user_id ": userDetails[index].user_id,
//             "user_photo": image,
//             "phone_no ": userDetails[index].phone_no,
//             "user_email": userDetails[index].user_email,
//             "designation": userDetails[index].designation,
//             "company": companyDetails[0].company_name
//         });

//         //console.log("userDetailResponseList", userDetailResponseList);

//     }

// }


const saveGoal = async (goalId, userIdList) => {
    let userArrayList = [];
    let goalListQuery = [];
    let goalFocusStrengthListQuery = []
    let goalMilestoneListQuery = []
    let goalPerformanceInfluencerListQuery = []
    let goalDocumentListQuery = []
    let goalMilestoneIdList = [];
    let goalExist = [];
    let milestoneIdList = [];
    console.log("userIdList", userIdList);
    let mileStoneCount = 0;
    let setMileStoneList = [];

    getGoalCloneDetail = await GoalHelper.getGoalCloneDetailByGoalIDUserIdAndStatus(goalId, userIdList, dbConn);
    console.log("getGoalCloneDetail", getGoalCloneDetail);

    if (getGoalCloneDetail.length) {
        goalExist = getGoalCloneDetail;
    }
    else {
        goalExist = await GoalHelper.getGoalDetailByGoalIDUserIdAndStatus(goalId, userIdList, dbConn);
    }
    console.log("goalExist", goalExist);

    if(goalExist.length == 0){
        return 1;
    }
    const userListWithoutGoal = userIdList.filter(element => !goalExist.some((goalList => goalList.user_id == element)));
    console.log("userListWithoutGoal: ", userListWithoutGoal);

    // Get goal_focus_strength_area tables goal_id,goal_milestones_action_id and version
    // Get goal_milestones table with goal_id and version
    // Get goal_performance_influencer table with goal_id and version
    // Get goal_documents table with goal_id and version
    if (userListWithoutGoal.length) {
        for (let index = 0; index < userListWithoutGoal.length; index++) {
            const userId = userListWithoutGoal[index];
            goalListQuery.push([
                userId,
                userId,
                userId,
                1,
                0,
                1,
                todayDateTime,
                todayDateTime
            ])

        }
    }
    console.log("goalListQuery :", goalListQuery);
    // Set New Goal 
    const goalResult = await GoalHelper.setGoalDetail(goalListQuery, dbConn);
    console.log("goalResult: ", goalResult);
    const goalIdList = goalResult.insertIdList;
    const version = goalExist[0].version;
    const goalFocusStrengthResult = await GoalHelper.getGoalFocusStrengthGoalIdActionIdAndVersion(goalId, version, dbConn);
    const goalMilestoneResult = await GoalHelper.getGoalMilestoneGoalIdAndVersion(goalId, version, dbConn);
    const goalPerformanceInfluencerResult = await GoalHelper.getGoalPerformanceInfluencerGoalIdAndVersion(goalId, version, dbConn);
    const goalDocumentResult = await GoalHelper.getGoalDocumentGoalIdAndVersion(goalId, version, dbConn);


    console.log("goalFocusStrengthResult: ", goalFocusStrengthResult);
    console.log("goalMilestoneResult: ", goalMilestoneResult);
    mileStoneCount = goalMilestoneResult.length;
    console.log("goalPerformanceInfluencerResult: ", goalPerformanceInfluencerResult);
    console.log("goalDocumentResult: ", goalDocumentResult);


    // If any goal id is save in table 
    if (goalIdList.length) {
        for (let goalIndex = 0; goalIndex < goalIdList.length; goalIndex++) {
            const goalId = goalIdList[goalIndex];
            userIdWithGoal = userListWithoutGoal[goalIndex]
            // Set strength Area

            if (goalFocusStrengthResult.length) {
                for (let focusIndex = 0; focusIndex < goalFocusStrengthResult.length; focusIndex++) {
                    const focusElement = goalFocusStrengthResult[focusIndex];
                    goalFocusStrengthListQuery.push([
                        goalId,
                        focusElement.goal_area_desc,
                        focusElement.goal_area_tag,
                        focusElement.goal_area_seq,
                        todayDateTime,
                        todayDateTime,
                        userIdWithGoal,
                        userIdWithGoal,
                        focusElement.goal_milestones_action_id,
                        version,
                        focusElement.contributor_id

                    ])
                }
            }
            if (goalPerformanceInfluencerResult.length) {
                for (let influencerIndex = 0; influencerIndex < goalPerformanceInfluencerResult.length; influencerIndex++) {
                    const influencerElement = goalPerformanceInfluencerResult[influencerIndex];
                    goalPerformanceInfluencerListQuery.push([
                        goalId,
                        influencerElement.goal_performance_influencer_desc,
                        influencerElement.goal_performance_influencer_dt,
                        influencerElement.goal_performance_influencer_target_value,
                        influencerElement.goal_performance_influencer_actual_value,
                        influencerElement.goal_performance_influencer_actual_unit,
                        influencerElement.goal_performance_influencer_actual_imogi,
                        influencerElement.goal_performance_influencer_sign,
                        influencerElement.goal_performance_influencer_unit,
                        influencerElement.goal_performance_influencer_actual_dt,
                        todayDateTime,
                        todayDateTime,
                        userIdWithGoal,
                        userIdWithGoal,
                        version
                    ]);

                }
            }

            if (goalDocumentResult.length) {
                // 
                for (let documentIndex = 0; documentIndex < goalDocumentResult.length; documentIndex++) {
                    const documentElement = goalDocumentResult[documentIndex];
                    goalDocumentListQuery.push([
                        userIdWithGoal,
                        documentElement.goal_document_title,
                        documentElement.goal_document_name,
                        documentElement.goal_document_thumb,
                        documentElement.goal_document_type,
                        documentElement.goal_document_size,
                        goalId,
                        todayDateTime,
                        todayDateTime,
                        version
                    ]);
                }
            }

            if (goalMilestoneResult.length) {
                for (let milestoneIndex = 0; milestoneIndex < goalMilestoneResult.length; milestoneIndex++) {
                    const milestoneElement = goalMilestoneResult[milestoneIndex];
                    goalMilestoneListQuery.push([
                        goalId,
                        milestoneElement.goal_milestones_desc,
                        milestoneElement.milestone_completed_action,
                        milestoneElement.milestone_total_action,
                        milestoneElement.goal_milestones_dt,
                        milestoneElement.goal_milestones_target_value,
                        milestoneElement.goal_milestones_unit,
                        milestoneElement.goal_milestones_sign,
                        milestoneElement.goal_milestones_value,
                        milestoneElement.goal_milestones_sequence,
                        todayDateTime,
                        todayDateTime,
                        userIdWithGoal,
                        userIdWithGoal,
                        version
                    ]);
                    goalMilestoneIdList.push(milestoneElement.goal_milestones_id);
                }
            }

        }
    }

    console.log("goalFocusStrengthListQuery: ", goalFocusStrengthListQuery);
    console.log("goalPerformanceInfluencerListQuery: ", goalPerformanceInfluencerListQuery);
    console.log("goalDocumentListQuery: ", goalDocumentListQuery);
    console.log("goalMilestoneListQuery: ", goalMilestoneListQuery);
    if (goalFocusStrengthListQuery.length) {
        const setFocusStrengthResult = await GoalHelper.setFocusStrengthArea(goalFocusStrengthListQuery, dbConn);
        console.log("setFocusStrengthResult: ", setFocusStrengthResult);
    }

    if (goalPerformanceInfluencerListQuery.length) {
        const setPerformanceInfluencerResult = await GoalHelper.setPerformanceInfluencer(goalPerformanceInfluencerListQuery, dbConn);
        console.log("setPerformanceInfluencerResult: ", setPerformanceInfluencerResult);
    }

    // setGoalDocuments
    if (goalDocumentListQuery.length) {
        const setGoalDocumentResult = await GoalHelper.setGoalDocuments(goalDocumentListQuery, dbConn);
        console.log("setGoalDocumentResult: ", setGoalDocumentResult);
    }
    if (goalMilestoneListQuery.length) {
        const setGoalMilestonesResult = await GoalHelper.setGoalMilestonesWithVersion(goalMilestoneListQuery, dbConn);
        console.log("setGoalMilestonesResult: ", setGoalMilestonesResult);
        milestoneIdList = setGoalMilestonesResult.insertIdList;
    }


    console.log("goalMilestroneIdList: : ", goalMilestoneIdList);
    goalMilestoneIdList = [...new Set(goalMilestoneIdList)];
    console.log("goalMilestroneIdListNew : ", goalMilestoneIdList);

    let milestoneActionListById = [];
    let simpleObject = {};
    let mileStoneActionLength = 0;
    let setgoalMilestoneActionResultData = [];
    let goalMilestoneActionIdList = [];
    if (goalMilestoneIdList.length) {
        const setgoalMilestoneActionResult = setgoalMilestoneActionResultData = await GoalHelper.getGoalMilestonesActionWithGoalMilestroneIdList(goalId, version, goalMilestoneIdList, dbConn);
        console.log("setgoalMilestoneActionResult: ", setgoalMilestoneActionResult);
        mileStoneActionLength = setgoalMilestoneActionResult.length;
        console.log("mileStoneActionLength: ", mileStoneActionLength);
        for (let mileStoneActionndex = 0; mileStoneActionndex < setgoalMilestoneActionResult.length; mileStoneActionndex++) {
            const mileStoneActionlement = setgoalMilestoneActionResult[mileStoneActionndex];
            goalMilestoneActionIdList.push(mileStoneActionlement.goal_milestones_action_id);

            // milestoneActionListById[mileStoneActionlement.goal_milestones_id].push(mileStoneActionlement);
            simpleObject[mileStoneActionlement.goal_milestones_id] = (simpleObject[mileStoneActionlement.goal_milestones_id] ?? 0) + 1;
        }
    }

    console.log("simpleObject: ", simpleObject);
    const keyList = Object.values(simpleObject)
    console.log("keyList: ", keyList);
    console.log("milestoneActionListById: ", milestoneActionListById);
    let globalActionList = []
    let actionMilestionQueryList = [];
    if (milestoneIdList.length) {
        let userPointer = 0;
        let globalPointer = 1;
        let mileStoneActionIndex = 0;
        let gloablCounter = 0;
        for (let userIndex = 0; userIndex < userListWithoutGoal.length; userIndex++) {
            const userId = userListWithoutGoal[userIndex];
            let mileStoneActionGlobal = 0;
            for (let mileStoneCountIndex = 0; mileStoneCountIndex < mileStoneCount; mileStoneCountIndex++) {
                const keyIndex = keyList[mileStoneCountIndex];

                for (let actionIndex = 0; actionIndex < keyIndex; actionIndex++) {
                    console.log("userId: ", userId);
                    console.log("keyIndex: ", keyIndex);
                    console.log("milestoneIdList_gloablCounter: ", milestoneIdList[gloablCounter]);
                    console.log("mileStoneActionGlobal: ", mileStoneActionGlobal);
                    const singleActionElement = setgoalMilestoneActionResultData[mileStoneActionGlobal];
                    actionMilestionQueryList.push([
                        milestoneIdList[gloablCounter],
                        goalId,
                        todayDateTime,
                        todayDateTime,
                        userId,
                        userId,
                        0,
                        version
                    ]);
                    mileStoneActionGlobal++;
                }
                gloablCounter++;

            }

        }
        console.log("actionMilestionQueryList: ", actionMilestionQueryList);
        console.log("actionMilestionQueryList: ", actionMilestionQueryList.length);
        let milestoneActionResultIdList =[];
        if(actionMilestionQueryList.length){
            const milestoneActionResult = await GoalHelper.setMilestoneActionWithGoalMilestoneId(actionMilestionQueryList, dbConn);
            console.log("milestoneActionResult: ", milestoneActionResult);
            milestoneActionResultIdList = milestoneActionResult.insertIdList;
        }
        
        console.log("goalMilestoneActionIdList: ", goalMilestoneActionIdList);
        let getMilestoneActionDocumentResult = [];
        if(goalMilestoneActionIdList.length){
            getMilestoneActionDocumentResult = await GoalHelper.getGoalMilestoneActionDocumentByActionIdList(goalMilestoneActionIdList, version, dbConn);
            console.log("getMilestoneActionDocumentResult: ", getMilestoneActionDocumentResult);
            console.log("getMilestoneActionDocumentResult length: ", getMilestoneActionDocumentResult.length);
        }
        
        let actionDocumentObject = {};
        for (let actionDocumentIndex = 0; actionDocumentIndex < getMilestoneActionDocumentResult.length; actionDocumentIndex++) {
            const actionDocumentElement = getMilestoneActionDocumentResult[actionDocumentIndex];
            actionDocumentObject[actionDocumentElement.goal_milestones_action_id] = (actionDocumentObject[actionDocumentElement.goal_milestones_action_id] ?? 0) + 1;

        }
        const actionDocumentList = Object.values(actionDocumentObject)
        console.log("keyList: ", actionDocumentList);


        let documentGlobalCounter = 0;
        let milestoneActionDocumentListQuery = [];
        let singleUserPointer = 0;
        
        //
        let documentElementCount = 0; 
        let getDocumentElementCount = 0;
        // let mileStoneFocusAreaQueryList= [];
        let singleUserDocumentPointer = 0;
        let singleUserDocumentCount = milestoneActionResultIdList.length / userListWithoutGoal.length;
        for (let mileStoneActionIndex = 0; mileStoneActionIndex < milestoneActionResultIdList.length; mileStoneActionIndex++) {
            // console.log("singleUserCount: ",singleUserDocumentCount);
            const mileStoneActionId= milestoneActionResultIdList[singleUserDocumentPointer];
            const userId = userListWithoutGoal[singleUserDocumentPointer];
            // console.log("userId FocusArea : ",userId);
            // console.log("userId FocusArea mileStoneActionId : ",mileStoneActionId);
            if((mileStoneActionIndex +1) % singleUserDocumentCount == 0){
                singleUserDocumentPointer++;
            }
            if((mileStoneActionIndex ) % singleUserDocumentCount == 0){
                documentElementCount = 0; 
                getDocumentElementCount = 0;
            }
            
            for (let documentIndex = 0; documentIndex < actionDocumentList.length; documentIndex++) {
                const documentSingleElementCount = actionDocumentList[documentElementCount];
                for (let index = 0; index < documentSingleElementCount; index++) {
                    const focusAreaelement = getMilestoneActionDocumentResult[getDocumentElementCount];
                    console.log("focusDocumetIndex:  ",getMilestoneActionDocumentResult[getDocumentElementCount]);
                    milestoneActionDocumentListQuery.push([
                        userId,
                        goalId,
                        mileStoneActionId,
                        focusAreaelement.action_document_name,
                        focusAreaelement.action_goal_document,
                        focusAreaelement.action_document_size,
                        focusAreaelement.action_document_thumb,
                        focusAreaelement.action_document_type,
                        todayDateTime,
                        todayDateTime,
                        version
                    ]);
                    getDocumentElementCount++;

                    
                }
                documentElementCount++;
                break;
                
            }
        }
        //
        // for (let mileStoneActionIndex = 0; mileStoneActionIndex < milestoneActionResultIdList.length; mileStoneActionIndex++) {
        //     let singleUserCount = milestoneActionResultIdList.length / userListWithoutGoal.length;
        //     const mileStoneActionId= milestoneActionResultIdList[mileStoneActionIndex];
        //     const userId = userListWithoutGoal[singleUserPointer];
        //     console.log("userId MA : ",userId);
        //     singleUserPointer++;
        //     if(singleUserPointer % mileStoneActionIndex == 0){
        //         singleUserPointer = 0 ;
        //     }
        //     for (let mileStoneDocumentIndex = 0; mileStoneDocumentIndex < getMilestoneActionDocumentResult.length; mileStoneDocumentIndex++) {
        //         const documentElement = getMilestoneActionDocumentResult[mileStoneDocumentIndex];
        //         milestoneActionDocumentListQuery.push([
        //             userId,
        //             goalId,
        //             mileStoneActionId,
        //             documentElement.action_document_name,
        //             documentElement.action_goal_document,
        //             documentElement.action_document_size,
        //             documentElement.action_document_thumb,
        //             documentElement.action_document_type,
        //             todayDateTime,
        //             todayDateTime,
        //             version
        //         ]);
        //     }

        // }

        console.log("milestoneActionDocumentListQuery: ",milestoneActionDocumentListQuery)
        if(milestoneActionDocumentListQuery.length){
            const mileStoneDocumentResult = await GoalHelper.setMileStoneDocumentWithActionId(milestoneActionDocumentListQuery, dbConn);
            console.log("mileStoneDocumentResult: ",mileStoneDocumentResult)
        }
        
        let getMilestoneActionFocusAreaResult = [];
        if(goalMilestoneActionIdList.length){
            getMilestoneActionFocusAreaResult = await GoalHelper.getGoalMilestoneActionFocusAreaByActionIdList(goalMilestoneActionIdList, version, dbConn);
            console.log("getMilestoneActionFocusAreaResult: ", getMilestoneActionFocusAreaResult);
            console.log("getMilestoneActionFocusAreaResult length: ", getMilestoneActionFocusAreaResult.length);
        }
        

        let milestoneFocusAreaObject = {};
        for (let milestoneActionFocusAreaIndex = 0; milestoneActionFocusAreaIndex < getMilestoneActionFocusAreaResult.length; milestoneActionFocusAreaIndex++) {
            // const element = array[milestoneActionFocusAreaIndex];
            const actionFocusElement = getMilestoneActionFocusAreaResult[milestoneActionFocusAreaIndex];
            milestoneFocusAreaObject[actionFocusElement.goal_milestones_action_id] = (milestoneFocusAreaObject[actionFocusElement.goal_milestones_action_id] ?? 0) + 1;
            
        }

        const actionFocusAreaList = Object.values(milestoneFocusAreaObject)
        console.log("actionFocusAreaList: ", actionFocusAreaList);



        let singleUserFocusPointer = 0;
        let singleUserFocusCount = milestoneActionResultIdList.length / userListWithoutGoal.length;
        let focusGlobalAreaCount = 0;
        let sampleArray = [1,2,3,4,5,6,7,8];
        let focusAreaElementCount = 0; 
        let getFocusAreaElementCount = 0;
        let mileStoneFocusAreaQueryList= [];
        for (let mileStoneActionIndex = 0; mileStoneActionIndex < milestoneActionResultIdList.length; mileStoneActionIndex++) {
            console.log("singleUserCount: ",singleUserFocusCount);
            const mileStoneActionId= milestoneActionResultIdList[mileStoneActionIndex];
            const userId = userListWithoutGoal[singleUserFocusPointer];
            console.log("userId FocusArea : ",userId);
            console.log("userId FocusArea mileStoneActionId : ",mileStoneActionId);

            if((mileStoneActionIndex +1) % singleUserFocusCount == 0){
                singleUserFocusPointer++;
            }
            
            if((mileStoneActionIndex ) % singleUserFocusCount == 0){
                focusAreaElementCount = 0; 
                getFocusAreaElementCount = 0;
            }
            
           
            
            for (let focusAreaIndex = 0; focusAreaIndex < actionFocusAreaList.length; focusAreaIndex++) {
                const focusAreaCount = actionFocusAreaList[focusAreaElementCount];
                console.log("focusAreaCountL: ",focusAreaCount)
                // if(focusAreaElementCount == focusAreaCount){
                //     break;
                // }
                for (let index = 0; index < focusAreaCount; index++) {
                    const focusAreaelement = getMilestoneActionFocusAreaResult[getFocusAreaElementCount];
                    console.log("focusAreaIndex:  ",getMilestoneActionFocusAreaResult[getFocusAreaElementCount])
                    mileStoneFocusAreaQueryList.push([
                        userId,
                        goalId,
                        focusAreaelement.goal_area_tag,
                        mileStoneActionId,
                        todayDateTime,
                        todayDateTime,
                        version
                    ]);
                    getFocusAreaElementCount++;

                    
                }
                focusAreaElementCount++;
                break;
                
            }

            // for (let focusAreaIndex = 0; focusAreaIndex < actionFocusAreaList.length; focusAreaIndex++) {
            //     const focusAreaCount = actionFocusAreaList[focusAreaIndex];
            //     for (let focusAreaCountIndex = 0; focusAreaCountIndex < array.length; focusAreaCountIndex++) {
            //         const element = array[focusAreaCountIndex];
                    
            //     }
                
            // }

            // for (let mileStoneDocumentIndex = 0; mileStoneDocumentIndex < getMilestoneActionDocumentResult.length; mileStoneDocumentIndex++) {
            //     const documentElement = getMilestoneActionDocumentResult[mileStoneDocumentIndex];
            //     milestoneActionDocumentListQuery.push([
            //         userId,
            //         goalId,
            //         mileStoneActionId,
            //         documentElement.action_document_name,
            //         documentElement.action_goal_document,
            //         documentElement.action_document_size,
            //         documentElement.action_document_thumb,
            //         documentElement.action_document_type,
            //         todayDateTime,
            //         todayDateTime,
            //         version
            //     ]);
            // }

        }
        console.log("mileStoneFocusAreaQueryList: ",mileStoneFocusAreaQueryList);
        if(mileStoneFocusAreaQueryList.length){
            const milestoneActionFocusAreaWithActionIdResult = await GoalHelper.setMilestoneFocusAreaWithActionIdList(mileStoneFocusAreaQueryList, dbConn);
            console.log("milestoneActionFocusAreaWithActionIdResult: ",milestoneActionFocusAreaWithActionIdResult);
        }
       
    }

    console.log("globalActionList:", globalActionList);
  
    // if (goalExist == 0) {
    //     const goalCloneResult = await GoalHelper.getGoalCloneDetailsByGoalIdAndStatus(goalId, dbConn);
    //     if (goalCloneResult.length) {
    //         goalExistResult = goalCloneResult;
    //     }
    //     else {
    //         goalExistResult = await GoalHelper.getGoalDetailsByGoalIdAndStatus(goalId, dbConn);
    //     }

    // }
    // console.log("goalExistResult", goalExistResult);
    // goalVersion = goalExistResult[0].version;
    // console.log("goalVersion",goalVersion);

    // const cloneDetails = await GoalHelper.getGoalCloneDetailByGoalIDUserIdArchiveActiveAndStatus(userIdList, goalId, dbConn);
    // console.log("cloneDetails",cloneDetails);

    // if (cloneDetails.length) {
    //     allExists = cloneDetails;
    // }
    // else {
    //     allExists = await GoalHelper.getGoalDetailByGoalIDUserIdArchiveActiveAndStatus(userIdList, goalId, dbConn);
    // }
    // console.log("allExists",allExists);

    // if (goalExistResult != 0 && allExists.length == 0) {

    // const getFocusStrengthArea = await GoalHelper.getFocusStrengthAreaDetailsByGoalIdMilstoneActionIdAndVersion(goalId, goalVersion, dbConn);
    // console.log("getFocusStrengthArea :", getFocusStrengthArea);
    // const getGoalMilestoneDetails = await GoalHelper.getGoalMilestoneDetailsByGoalIdAndVersion(goalId, goalVersion, dbConn);
    // console.log("getGoalMilestoneDetails :", getGoalMilestoneDetails);
    // const getGoalPerformanceInfluencerDetails = await GoalHelper.getGoalPerformanceInfluencerDetailsByGoalIdAndVersion(goalId, goalVersion, dbConn);
    // console.log("getGoalPerformanceInfluencerDetails: ", getGoalPerformanceInfluencerDetails);
    // const getGoalDocumentsDetails = await GoalHelper.getGoalDocumentsDetailsByGoalIdAndVersion(goalId, goalVersion, dbConn);
    // console.log("getGoalDocumentsDetails :", getGoalDocumentsDetails);

    // goalList = [[
    //     userIdList,
    //     '',
    //     userIdList,
    //     userIdList,
    //     '',
    //     1,
    //     0,
    //     1,
    //     todayDate,
    //     todayDate
    // ]
    // ]
    // console.log("goalList", goalList);
    // const goalDetails = await GoalHelper.setGoalDetail(goalList, dbConn);
    // console.log("goalDetails", goalDetails);


    //         if (getFocusStrengthArea) {
    // focusArray = [goalId,todayDate,todayDate,userId,userId,goalVersion];
    // console.log("focusArray",focusArray); 
    // const setFocusStrengthArea = await GoalHelper.insertGoalFocusStrengthArea(focusArray,dbConn);
    //         }

    //         if (getGoalPerformanceInfluencerDetails) {
    //             influencerArray = [goalId,todayDate,todayDate,userId,userId,goalVersion];
    // const setInfluencer = await GoalHelper.setGoalPerformanceInfluencer(influencerArray,dbConn)
    //         }

    //         if (getGoalDocumentsDetails) {
    //         documentArray = [userId,
    //             getGoalDocumentsDetails.goal_document_title, 
    //             getGoalDocumentsDetails.goal_document_name,
    //             getGoalDocumentsDetails.goal_document_thumb,
    //             getGoalDocumentsDetails.goal_document_type,
    //             getGoalDocumentsDetails.goal_document_size,
    //             goalId,
    //             todayDate,
    //             todayDate,
    //             goalVersion
    //         ];
    // const setDocument = await GoalHelper.setGoalDocuments(documentArray,dbConn)
    //         }
    // }

    if(goalResult.length){
        return goalResult.insertIdList;
    }
}

// Schedule 
const saveSchedule =async(shareDate, schedule,saveGoalList)=>{

    if(schedule == 0){
        let scheduleListQuery = [];
        for (let index = 0; index < userIdWithGoal.length; index++) {
            const singleUserId = userIdWithGoal[index];
            const goalId = saveGoalList[index];
            scheduleListQuery.push([
                goalId,
                shareDate,
                todayDate,
                singleUserId
            ]);
        }

        const goalScheduleResult = await GoalHelper.setGoalScheduleWithUserList(scheduleListQuery,dbConn);
        
    }
    else{
        const getUsers = await GoalHelper.getUsersFromArray(userIdWithGoal, dbConn);
    console.log("getUsers", getUsers);
    for (let index = 0; index < getUsers.length; index++) {
        const userElement = getUsers[index];
        const goalId = saveGoalList[index];

        
    }
    // Update multiple columns row
    // send notification
    }
    
}
//send to api 
const sendToUser = async (goalId, schedule, shareDate, userIdList) => {
    console.log("schedule", schedule);
    console.log("shareDate", shareDate);
    let customShareDate;
    console.log("userIdList", userIdList);
    if (schedule == 1 || shareDate == '') {
        customShareDate = todayDate;
    }
    else {
        customShareDate = shareDate;
    }
    //console.log("shareDate",customShareDate); 
    //ask share date 

    const getGoalDetail = await GoalHelper.getGoalCloneDetailByGoalIDAndStatus(goalId, dbConn);
    //console.log("getGoalDetail",getGoalDetail);
    if (getGoalDetail.length) {
        goalData = getGoalDetail;
    }
    else {
        goalData = await GoalHelper.getGoalDetailByGoalIDAndStatus(goalId, dbConn);
    }
    //console.log("goalData",goalData);

    

    // const saveGoalList = await saveGoal(goalId, userIdList);
    const saveGoalList = [0,0];
        await saveSchedule(customShareDate, schedule,saveGoalList)

    // for (let index = 0; index < getUsers.length; index++) {
    //     // const userDetail = getUsers[index];
    //     userEmail = getUsers[index].user_email;
    //     const userId = getUsers[index].user_id;

    //     link = `${baseUrl}/share_profile/goal/employee/${goalId}`;




    // }

}

exports.handler = async (event) => {
    try {
        let response;
        console.log("eventRequest ",event);
        const token = event.headers.authorization;
        const requestBody = JSON.parse(event.body);
        //userId = requestBody.user_id;
        goalId = requestBody.goal_id.trim()
        shareDate = requestBody.share_date.trim();
        schedule = requestBody.schedule.trim();

        console.log("goalId", goalId);
        // console.log("userIdArray", userId);
        //companyId = requestBody.company_id.trim();


        // returning "credential not set", if user_id is not passing in the request
        // if (!userId) {
        //     return response = {
        //         statusCode: 401,
        //         headers: responseHeaders,
        //         body: JSON.stringify({
        //             message: 'Credential not set',
        //             status: 0,
        //         }),
        //     };
        // }

        // returning "acccess denied", if token is undefined or not passing in the request
        if (!token) {
            return response = {
                statusCode: 403,
                headers: responseHeaders,
                body: JSON.stringify({
                    message: 'Access denied'
                }),
            };
        }

        // returning "acccess denied", if token is expired or invalid
        if (await TokenUtils.verifyToken(token, "commonGetDepartmentUsersListAPI", dbConn) == false) {
            return response = {
                statusCode: 403,
                headers: responseHeaders,
                body: JSON.stringify({
                    message: 'Access denied'
                }),
            };
        }
        const tokenData = await TokenUtils.getTokenData(token);
        todayDate = moment().tz(tokenData.time_zone).format('YYYY-MM-DD');
        todayDateTime = moment().tz(tokenData.time_zone).format('YYYY-MM-DD  HH:mm:ss');
        // moment().format('YYYY-MM-DD HH:mm:ss');


        //const userList = await userDeptList(requestBody);
        const sendTo = await sendToUser(goalId, schedule, shareDate, requestBody.user_id);

        return {
            statusCode: 200,
            headers: responseHeaders,
            body: JSON.stringify({
                message: 'Action details',
                status: 1
            })
        }

    } catch (e) {
        console.log("Catch: ", e);
        return {
            statusCode: 500,
            headers: responseHeaders,
            body: JSON.stringify({
                message: 'Something went wrong'
            }),
        };
    }
};