//���Ӽ��е�һ��Ԫ��Ϊ��׼�Ƚϣ���ͬ�Ľ��������Ӽ���+0.5��֮����ͬ�ļ�0.5������ֵ�ļ�1������ѭ����αȽϣ�ֱ��û�����Ӽ�����
//״̬ת�Ƶľ���������㷨���Ѿ����Ǻ���Ҫ��ֻ�豣֤�Ƚϵ�ͬһ�еķ���
#include <iostream>
using namespace std;

int main()
{
    int nodeNum;
    cout << "������ڵ����" << endl;
    cin >> nodeNum;
    float nodeBelong[20];
    cout << "����������ÿ���ڵ�ĳ�ʼ����״̬�Ӽ�" << endl;
    for (int i = 0; i < nodeNum; i++)
    {
        cin >> nodeBelong[i];
    }
    int change[20][2];
    cout << "����������ÿ���ڵ�ʶ���ַ��󵽴���µ�״̬����1 1" << endl;
    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> change[i][j];
        }
    }

    //����ͬ��״̬�Ӽ����бȽ�
    int currentSubNodeNum = 2;
    for (int i = 0; i < currentSubNodeNum; i++)
    {
        int compareArray[20];
        int m = 0;
        //��������ͬ�Ӽ���Ӧ�Ľڵ��±�
        for (int j = 0; j < nodeNum; j++)
        {

            if (nodeBelong[j] == i)
            {
                compareArray[m++] = j;
            }
        }
        //���������õ�����ͬ�Ӽ��Ľڵ㿪ʼ�Ƚ�״̬ת�ƺ��Ƿ���һ���Ӽ���
        float record = 0; //��¼.5��ֵ
        for (int j = 0; j < m; j++)
        {
            int compare = compareArray[0];
            for (int n = 0; n < 2; n++)
            { //�����һ���Ƚϣ����ڵ�ת�������һ���ڵ�ת������һ���Ӽ���Ԫ�����������Ӧֵ��+0.5
                if (nodeBelong[change[compare][n]] != nodeBelong[change[compareArray[j]][n]])
                {
                    nodeBelong[compareArray[j]] += 0.5;
                    record = nodeBelong[compareArray[j]];
                    break;
                }
            }
        }
        cout << "record" << record << endl;
        //.5�ļ�.5������.5�ļ�1,���record=0��˵���˴�û�����Ӽ�����
        if (record == 0)
            continue;
        else
        {
            currentSubNodeNum++;
            i = 0; //���¿�ʼ
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