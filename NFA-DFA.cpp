//先求出所有节点的eplison闭包，之后求出每个节点经过一个字母后的节点（采用矩阵存储节点之间的转换），并将该节点的闭包一起存入
//temp集合中，检验该新产生的集合是否已存在在v中决定是否是一个新产生的集合
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
void printf(const set<int> &a)
{
    if (a.size() == 0)
        return;
    cout << '{';
    set<int>::iterator it = a.begin();
    for (; it != a.end(); ++it)
        cout << *it << ',';
    cout << '\b' << '}'; //将光标向前移动，去掉‘,’
}
bool isEqual(set<int> &a, set<int> &b)
{
    if (a.size() != b.size())
        return false;
    set<int>::iterator ita = a.begin();
    set<int>::iterator itb = b.begin();
    for (; ita != a.end(); ++ita, ++itb)
    {
        if (*ita != *itb)
            return false;
    }

    return true;
}

int main()
{
    int charNum;
    cout << "请输入有多少个字母表中字符个数（不包含epsilon）：" << endl;
    cin >> charNum;
    cout << "请输入字符（小写，保留e，e默认为epsilon，无需输入）：" << endl;
    char *changeCharArray = new char[charNum + 1];
    *changeCharArray = 'e'; //changeCharArray[]存储字符
    for (int i = 1; i < charNum + 1; ++i)
        cin >> changeCharArray[i];

    cout << "请输入节点个数:" << endl;
    int nodeNum;
    cin >> nodeNum;
    int *node = new int[nodeNum];
    //对节点初始化
    for (int i = 0; i < nodeNum; ++i)
        node[i] = i;

    char change[30][30] = {}; //用矩阵存储转换函数
    cout << "请输入转移箭弧，格式为（开始节点编号 字符 终点节点编号 ）如 0 e 1。输入0 e 0结束输入" << endl;
    int s, e;
    char c;
    while (cin >> s >> c >> e)
    {
        if (s == 0 && e == 0 && c == 'e')
            break;
        change[s][e] = c;
    };
    set<int> *node_epsilon = new set<int>[nodeNum]; //计算每个节点的闭包
    for (int i = 0; i < nodeNum; i++)
    {
        node_epsilon[i].insert(i); //把自身加入进去
        queue<int> que;
        que.push(i); //通过队列实现自动化，广度查找
        while (!que.empty())
        {
            int element = que.front();
            for (int j = 0; j < nodeNum; j++)
            {
                if (change[element][j] == 'e')
                {
                    node_epsilon[i].insert(j);
                    que.push(j);
                }
            }
            que.pop();
        }
    }
    vector<set<int>> v;
    v.push_back(node_epsilon[0]); //从初始起点开始
    int it = 0;
    while (it < v.size())
    {
        // 依次输出每个过程
        cout << "s" << it << ":";
        printf(v[it]);
        cout << '\t' << '\t';
        for (int i = 1; i < charNum + 1; ++i)
        {
            char c = changeCharArray[i];
            set<int> temp;
            for (set<int>::iterator m = v[it].begin(); m != v[it].end(); ++m)
            {
                for (int j = 0; j < nodeNum; j++)
                {
                    if (change[*m][j] == c) //将得出的节点连同eplison闭包加入temp中
                    {
                        temp.insert(node_epsilon[j].begin(), node_epsilon[j].end());
                    }
                }
            }
            printf(temp);
            cout << '\t' << '\t';
            //看是否存在
            bool exists = false;
            for (int q = 0; q < v.size(); q++)
            {

                if (isEqual(v[q], temp))
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
            {
                v.push_back(temp);
            }
        }
        it++;
        cout << endl;
    }
}