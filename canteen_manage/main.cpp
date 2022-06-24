#include "analysis.h"
#include "users.h"
#include "windows.h"
using namespace std;

int main()
{
    int                  nOrder;
    CCard           cards[MAXNUM];
    CWindow      wins[100];
    cout<<"ϵͳ���ڳ�ʼ�����Ե�..."<<endl;

    BuildAccounts (cards,MAXNUM-1);
    LoadPreTimes (wins);
    system              ("pause");
    system              ("cls");
    while(true)
    {
        cout<<"ʱ�䣺"<<CWindow::sm_Time<<endl;
        cout<<R"(
                 /**************************/
                 *��ͨ�û���
                    1������
                    2����Ƭ����
                    3����Ƭ����
                 *����Ա��
                    4��ģ����Ϣ��ѯ
                    5����������ִ�У��赼�����ݣ�
                    6����·�鲢���Ѽ�¼����ѯ
                    7���������Ѽ�¼����ѯ
                    8�����ڹ���
                 *ϵͳ��
                    9��ϵͳ�����빦��
                    10����ȫ���
                 /**************************/)"<<endl;
        cout<<"������ָ�";
        cin>>nOrder;
        if(nOrder==0) break;
        switch(nOrder)
        {
        case 1:
            BuildAccount(cards);
            break;
        case 2:
            ManageCard(cards);
            break;
        case 3:
            FormApplication(wins,cards);
            break;
        case 4:
            FuzzySearch(cards);
            break;
        case 5:
            OperateS(wins,cards);
            break;
        case 6:
            MergeWinLogs(wins,0);
            break;
        case 7:
            MergeWinLogs(wins,1);
            break;
        case 8:
            ManageWindow(wins);
            break;
        case 9:
            ManageAnalysis(wins,cards);
            break;
        case 10:
            EncryptApplications();
            break;
        default:
            cout<<"ָ�����"<<endl;
        }
        system("pause");
        system("cls");
    }
}
