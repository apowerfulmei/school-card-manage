#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define lose_times 100
#define default_code "8888"
#define IDINDEX             0 //卡片信息中卡号的次序
#define NAMEINDEX     1 //卡片信息中卡号的次序
#define STUIDINDEX     2 //卡片信息中卡号的次序
#define MAXNUM          10001


typedef struct SCardId
{
    //参数为卡号以及卡的状态
    string      s_Id;
    bool        bLost=false;
    struct     SCardId *next=nullptr;
}SCardId;

typedef struct SPeriodCharge
{
    //参数为时间段以及此时间段的消费金额
    string     s_Period;
    double   fCharge=0;
}SPeriodCharge;

class CCard
{
private:
/*********************************
*卡号以及卡片的挂失情况
*姓名
*学号
*使用期限
*密码
*余额
*剩余补卡次数
*********************************/
    SCardId *   ID=new SCardId;
    string          m_Name;
    string          m_SchoolNum;
    string          m_DueDate;
    string          m_Passwd;
    double        m_Balance;
    int                m_LeftTimes;
public:
/*********************************
*当前时间段的消费金额
*基本构造函数
*显示余额
*消费
*冻结挂失或解挂
*显示基本信息
*充值
*验证密码是否正确
*补卡
*修改密码
*开户
*********************************/
    SPeriodCharge m_Sum;
    CCard();
    double   getBalance();
    bool        payCard(double num);
    bool        freezeCard(int order);
    string     getMessage(int order);
    void        chargeCard(double amount);
    bool        verifyPasswd(string input);
    bool        reopenAccount(string newid);
    void        changePasswd(string newcode);
    void        createCard(string _id,string _name,string _stu_id);
};
/**********************************
*系统函数
*字符串扩展功能，当匹配汉字串时要将?与*字符匹配两次
*生成卡号
*单一卡片管理
*返回用户信息
*单一卡片开户
*模糊查找功能
*查找学号对应的卡片信息
*判断两个时间是否处于同一时间段
*单一卡片管理函数重载
*批量卡片管理
*批量开户
*模糊匹配功能
**********************************/
void        ExpandStr(string & str);
string     CreateCardNumber(int i);
void        ManageCard(CCard *cards);
int           GetUserMessage(int choice);
void        BuildAccount(CCard * cards);
void        FuzzySearch(CCard * cards);
void        BuildAccounts(CCard * cards,int maxnum);
int           SearchCard(CCard * cards,string id,int index);
bool        MatchTime(string const &time1,string const &time2);
int           ManageCard(CCard &card,int order,int x,CCard * cards);
void        ManageCards(CCard *cards,ifstream & fin,string & due_time);
bool        FuzzyMatch(string const &str,string const &key,int start1,int start2);
#endif // USERS_H_INCLUDED
