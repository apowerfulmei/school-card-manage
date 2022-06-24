#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED
#include <vector>
#include "users.h"
#include "windows.h"


//���ܷ��������
/*********************************
*�������ļ����ж�·�鲢���������µ��ļ�
*���������в�������ѡ��
*����־�ļ�����д�ļ�
*��ȫ�����ѳ�ֵ��������
*��ʾ��ǰѧ�������뿨Ƭ����
*�ַ�����С�Ƚ�
*�ַ�����С�Ƚ�
*�ַ�����С�Ƚ�
*����ļ�����
*���ܷ����������
*��������򣬽���һ��λ�õ����ݷŵ����ʵ�λ��
*�ַ�����С�Ƚ�
*�ַ�����С�Ƚ�
*������������
*�����Ѽ�¼��������
*�ж�ָ���ַ����Ƿ������������
*�������ܵĹ���
*У�������ɺ���
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
