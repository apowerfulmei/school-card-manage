#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define lose_times 100
#define default_code "8888"
#define IDINDEX             0 //��Ƭ��Ϣ�п��ŵĴ���
#define NAMEINDEX     1 //��Ƭ��Ϣ�п��ŵĴ���
#define STUIDINDEX     2 //��Ƭ��Ϣ�п��ŵĴ���
#define MAXNUM          10001


typedef struct SCardId
{
    //����Ϊ�����Լ�����״̬
    string      s_Id;
    bool        bLost=false;
    struct     SCardId *next=nullptr;
}SCardId;

typedef struct SPeriodCharge
{
    //����Ϊʱ����Լ���ʱ��ε����ѽ��
    string     s_Period;
    double   fCharge=0;
}SPeriodCharge;

class CCard
{
private:
/*********************************
*�����Լ���Ƭ�Ĺ�ʧ���
*����
*ѧ��
*ʹ������
*����
*���
*ʣ�ಹ������
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
*��ǰʱ��ε����ѽ��
*�������캯��
*��ʾ���
*����
*�����ʧ����
*��ʾ������Ϣ
*��ֵ
*��֤�����Ƿ���ȷ
*����
*�޸�����
*����
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
*ϵͳ����
*�ַ�����չ���ܣ���ƥ�人�ִ�ʱҪ��?��*�ַ�ƥ������
*���ɿ���
*��һ��Ƭ����
*�����û���Ϣ
*��һ��Ƭ����
*ģ�����ҹ���
*����ѧ�Ŷ�Ӧ�Ŀ�Ƭ��Ϣ
*�ж�����ʱ���Ƿ���ͬһʱ���
*��һ��Ƭ����������
*������Ƭ����
*��������
*ģ��ƥ�书��
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
