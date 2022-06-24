#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED

#include "users.h"

#define upnum 20 //һ�������������������
#define RANGE 20//��������Բ���ʱ�ķ�Χ
#define INDEX 0
#define TOTALINDEX 1
#define TIMESINDEX 2

typedef struct SBox
{
    //�洢ָ���ԡ�����Լ�λ�Σ��Լ���¼����
    int      index;
    int      now;
    int      num=0;
    char  str[48];
} SBox;

typedef struct SWinLog
{
    //flag��ʾ�Ƿ�Ϊ�գ�logs��¼log����
    int     nFlag;
    char sLogs[48];
} SWinLog;

typedef struct SNode
{
    //�����������ݵĴ洢
    char    str[48];
    struct SNode *next=nullptr;
    struct SNode *last;
} SNode;

class CWindow
{
private:
/*********************************
*���ں�
*�ܹ����ѽ��
*���Ѵ���
*ʱ�䣬���������Լ�ʱ��
*********************************/
    int           m_Index;
    double   m_Total;
    int           m_Times;
public:
/*********************************
*ʱ�䣬Ϊ�����๲��
*�������캯��
*�鿴�������ڵ����Ѽ�¼������������
*�������Ѵ���
*������Ϣ��ʾ����
*��¼���Ѽ�¼
*������������
*********************************/
    static string sm_Time;
    CWindow();
    void        chkWinLog();
    void        loadTimes(int num);
    double   getMessage(int order);
    void        loadWinLog(string &log);
    bool        processApplication(CCard & card,double num,int pattern,string set_time);
};
/*********************************
*��������鲢
*�޸�����ʱ��
*����������˻�
*����wz�ļ�
*���ڹ���
*�ϲ����д������Ѽ�¼�����������ͳ�Ʋ���
*���ɵ�����������
*����������������
*********************************/
void            QuickSort();
void            ChangeTime();
void            FindConnection(string & id);
void            LoadPreTimes(CWindow * wins);
void            ManageWindow(CWindow * wins);
void            MergeWinLogs(CWindow * wins,int pattern);
void            FormApplication(CWindow * wins,CCard * cards);
SNode*      FormApplications(CWindow * wins,CCard * cards,SNode * cur,string & due_time);
#endif // WINDOWS_H_INCLUDED
