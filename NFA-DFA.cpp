//��������нڵ��eplison�հ���֮�����ÿ���ڵ㾭��һ����ĸ��Ľڵ㣨���þ���洢�ڵ�֮���ת�����������ýڵ�ıհ�һ�����
//temp�����У�������²����ļ����Ƿ��Ѵ�����v�о����Ƿ���һ���²����ļ���
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
    cout << '\b' << '}'; //�������ǰ�ƶ���ȥ����,��
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
    cout << "�������ж��ٸ���ĸ�����ַ�������������epsilon����" << endl;
    cin >> charNum;
    cout << "�������ַ���Сд������e��eĬ��Ϊepsilon���������룩��" << endl;
    char *changeCharArray = new char[charNum + 1];
    *changeCharArray = 'e'; //changeCharArray[]�洢�ַ�
    for (int i = 1; i < charNum + 1; ++i)
        cin >> changeCharArray[i];

    cout << "������ڵ����:" << endl;
    int nodeNum;
    cin >> nodeNum;
    int *node = new int[nodeNum];
    //�Խڵ��ʼ��
    for (int i = 0; i < nodeNum; ++i)
        node[i] = i;

    char change[30][30] = {}; //�þ���洢ת������
    cout << "������ת�Ƽ�������ʽΪ����ʼ�ڵ��� �ַ� �յ�ڵ��� ���� 0 e 1������0 e 0��������" << endl;
    int s, e;
    char c;
    while (cin >> s >> c >> e)
    {
        if (s == 0 && e == 0 && c == 'e')
            break;
        change[s][e] = c;
    };
    set<int> *node_epsilon = new set<int>[nodeNum]; //����ÿ���ڵ�ıհ�
    for (int i = 0; i < nodeNum; i++)
    {
        node_epsilon[i].insert(i); //����������ȥ
        queue<int> que;
        que.push(i); //ͨ������ʵ���Զ�������Ȳ���
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
    v.push_back(node_epsilon[0]); //�ӳ�ʼ��㿪ʼ
    int it = 0;
    while (it < v.size())
    {
        // �������ÿ������
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
                    if (change[*m][j] == c) //���ó��Ľڵ���ͬeplison�հ�����temp��
                    {
                        temp.insert(node_epsilon[j].begin(), node_epsilon[j].end());
                    }
                }
            }
            printf(temp);
            cout << '\t' << '\t';
            //���Ƿ����
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