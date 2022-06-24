#include "analysis.h"
#include "users.h"
#include "windows.h"
using namespace std;

int main()
{
    int                  nOrder;
    CCard           cards[MAXNUM];
    CWindow      wins[100];
    cout<<"系统正在初始化，稍等..."<<endl;

    BuildAccounts (cards,MAXNUM-1);
    LoadPreTimes (wins);
    system              ("pause");
    system              ("cls");
    while(true)
    {
        cout<<"时间："<<CWindow::sm_Time<<endl;
        cout<<R"(
                 /**************************/
                 *普通用户：
                    1、开户
                    2、卡片管理
                    3、卡片消费
                 *管理员：
                    4、模糊信息查询
                    5、批量操作执行（需导入数据）
                    6、多路归并消费记录并查询
                    7、快排消费记录并查询
                    8、窗口管理
                 *系统：
                    9、系统设置与功能
                    10、安全检测
                 /**************************/)"<<endl;
        cout<<"请输入指令：";
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
            cout<<"指令错误"<<endl;
        }
        system("pause");
        system("cls");
    }
}
