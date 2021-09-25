//以子集中第一个元素为基准比较，不同的将其所属子集号+0.5，之后相同的加0.5，大于值的加1；继续循环逐次比较，直至没有新子集产生
//状态转移的具体符号在算法中已经不是很重要，只需保证比较的同一列的符号
#include <iostream>
using namespace std;

int main()
{
    int nodeNum;
    cout << "请输入节点个数" << endl;
    cin >> nodeNum;
    float nodeBelong[20];
    cout << "请依次输入每个节点的初始所属状态子集" << endl;
    for (int i = 0; i < nodeNum; i++)
    {
        cin >> nodeBelong[i];
    }
    int change[20][2];
    cout << "请依次输入每个节点识别字符后到达的新的状态，如1 1" << endl;
    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> change[i][j];
        }
    }

    //对相同的状态子集进行比较
    int currentSubNodeNum = 2;
    for (int i = 0; i < currentSubNodeNum; i++)
    {
        int compareArray[20];
        int m = 0;
        //检索到相同子集对应的节点下标
        for (int j = 0; j < nodeNum; j++)
        {

            if (nodeBelong[j] == i)
            {
                compareArray[m++] = j;
            }
        }
        //根据上述拿到的相同子集的节点开始比较状态转移后是否在一个子集中
        float record = 0; //记录.5的值
        for (int j = 0; j < m; j++)
        {
            int compare = compareArray[0];
            for (int n = 0; n < 2; n++)
            { //都与第一个比较，将节点转换后与第一个节点转换后不在一个子集的元素所属数组对应值都+0.5
                if (nodeBelong[change[compare][n]] != nodeBelong[change[compareArray[j]][n]])
                {
                    nodeBelong[compareArray[j]] += 0.5;
                    record = nodeBelong[compareArray[j]];
                    break;
                }
            }
        }
        cout << "record" << record << endl;
        //.5的加.5，大于.5的加1,如果record=0，说明此次没有新子集产生
        if (record == 0)
            continue;
        else
        {
            currentSubNodeNum++;
            i = -1; //重新开始
            for (int j = 0; j < nodeNum; j++)
            {
                if (nodeBelong[j] == record)
                {
                    nodeBelong[j] += 0.5;
                }
                else if (nodeBelong[j] > record)
                {
                    nodeBelong[j]++;
                }
            }
        }
    }
    for (int i = 0; i < nodeNum; i++)
    {
        cout << nodeBelong[i] << endl;
    }
    return 0;
}
