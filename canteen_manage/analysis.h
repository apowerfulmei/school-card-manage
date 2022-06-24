#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED
#include <vector>
#include "users.h"
#include "windows.h"


//汇总分析与管理
/*********************************
*对消费文件进行多路归并排序并生成新的文件
*查找数据中不正常的选项
*向日志文件中书写文件
*安全的消费充值申请生成
*显示当前学生总数与卡片总数
*字符串大小比较
*字符串大小比较
*字符串大小比较
*清空文件内容
*汇总分析管理程序
*针对性排序，将第一个位置的数据放到合适的位置
*字符串大小比较
*字符串大小比较
*批量操作管理
*对消费记录进行重塑
*判断指定字符串是否存在于容器中
*分析功能的管理
*校验码生成函数
*********************************/
void        SortApplications();
void        FindUnexpect();
void        WriteLog(string log);
void        EncryptApplications();
void        ShowUserMessage();
bool        compare(SBox a,SBox b);
bool        compare1(SBox a,SBox b);
bool        compare4(SBox *a,SBox *b);
void        ClearLogs(string filename);
void        ReSortBox(SBox * box,int start,int until);
bool        compare2(CCard &card1,CCard &card2);
bool        compare3(CCard &card1,CCard &card2);
void        OperateS(CWindow * wins,CCard * cards);
void        ReshapeApplications(string & str,string num);
bool        PutInVector(vector<SBox> &box,string id);
void        ManageAnalysis(CWindow *wins,CCard *cards);
string      FormSafeCode(string log);
void        SafeStore(SNode * head);
#endif // ANALYSIS_H_INCLUDED
