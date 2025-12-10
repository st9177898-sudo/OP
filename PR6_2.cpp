#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool isipv4(const string &s)
{
    int parts = 0;
    int i = 0;
    int n = (int)s.size();
    while (i < n)
    {
        if (s[i] < '0' || s[i] > '9') return false;
        int val = 0;
        int digits = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            val = val * 10 + s[i] - '0';
            digits++;
            if (val > 255) return false;
            i++;
        }
        if (digits == 0) return false;
        parts ++;
        if (parts > 4) return false;
        if (i == n) break;
        if (s[i] != '.') return false;
        i++;
        if (i == n) return false;
    }
    return parts == 4;
}
    string cleanword(const string &token)
    {
        string res;
        for (int i = 0; i < (int)token.size(); i++)
        {
            char c = token[i];
            if (c >= 'A' && c <= 'Z')
                c = char(c - 'A' + 'a');
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                res.push_back(c);
        }
    return res;
    }


int main()
{
    int n;
    cout << "Кiлькiсть записiв у журналi: ";
    cin >> n;
    cin.ignore();
    vector<string> logs(n);
    cout << "Введiть " << n << " рядкiв журналу: " << endl;
    for (int i = 0; i < n; i++)
        getline(cin, logs[i]);
    map<string, int> wordfreq;
    set<string> ipset;
    map<string, vector<int>> indexbydate;
    int totalwotrds = 0;
    for (int i = 0; i < n; i++)
    {
        const string &line = logs[i];
        vector<string> tokens;
        string cur;
        for (int i = 0; i < (int)line.size(); i++)
        {
            char c = line[i];
            if (c == ' ' || c == '\t')
            {
                if (!cur.empty())
                {
                    tokens.push_back(cur);
                    cur.clear();
                }
            }
            else
                cur.push_back(c);
        }
        if (!cur.empty())
            tokens.push_back(cur);
        if (tokens.empty()) continue;
        string date = tokens[0];
        indexbydate[date].push_back(i);
        for (int j = 0; j < (int)tokens.size(); j++)
        {
            const string &tok = tokens[j];
            if (isipv4(tok))
                ipset.insert(tok);
            string w = cleanword(tok);
            if (!w.empty())
            {
                wordfreq[w]++;
                totalwotrds++;
            }
        }
    }
    string bestword;
    int bestcount = 0;
    for (map<string, int>::iterator it = wordfreq.begin(); it != wordfreq.end(); it++)
    {
        if (it->second > bestcount)
        {
            bestcount = it->second;
            bestword = it->first;
        }
    }
    float share = 0.0;
    if (totalwotrds > 0 && bestcount > 0)
        share = (float)bestcount * 100.0 / (float)totalwotrds;
    cout << "Частотний словник слiв: " <<endl;
    for (map<string, int>::iterator it = wordfreq.begin(); it != wordfreq.end(); it++)
        cout << it->first << " : " << it->second<< endl;
    cout << "Найчастiше слово: " << bestword << endl;
    cout << "Кiлькiсть використаннь: " << bestcount << endl;
    cout << "Частка вiд усiх слiв: " << share << endl;
    cout << "Ункальнi IP-адреси: "<< endl;
    if (ipset.empty())
        cout << "IP-адрес не знайдено" << endl;
    else
    {
        for (set<string>::iterator it = ipset.begin(); it != ipset.end(); it++)
            cout << *it << endl;
    }
    cout << "Пошук кiлькостi подiй за датою" << endl;
    cout << "Введiть дату: " << endl;
    string querydate;
    cin >> querydate;
    map<string, vector<int>>::iterator it = indexbydate.find(querydate);
    if (it == indexbydate.end())
        cout << "Для дати " << querydate << " подiй не знайдено" << endl;
    else
        cout << "Кiлькiсть подiй для дати " << querydate << ": "<< it->second.size() << endl;

    return 0;
}