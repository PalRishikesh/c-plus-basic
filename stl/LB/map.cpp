#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "Rishi";
    m[13] = "Arjun";
    m[2] = "Pal";
    m.insert({5, "Bheem"});
    cout << "Before Erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " Value: " << i.second << endl;
    }
    cout << "Finding 13 " << m.count(13) << endl;
    cout << "After Erase" << endl;
    // m.erase(13);
    for (auto i : m)
    {
        cout << i.first << " Value: " << i.second << endl;
    }

    auto it = m.find(5);
    for(auto ai=it; ai !=m.end();ai++){
        cout<<(*ai).first<<endl;
    }
}