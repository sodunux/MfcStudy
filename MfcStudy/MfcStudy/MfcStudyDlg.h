
// MfcStudyDlg.h : ͷ�ļ�
//


#pragma once

#include "TipDlg.h"

// CMfcStudyDlg �Ի���
class CMfcStudyDlg : public CDialogEx
{
// ����
public:
	CMfcStudyDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CMfcStudyDlg();

// �Ի�������
	enum { IDD = IDD_MFCSTUDY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
	afx_msg void OnBnClickedAddButton();
private:
	CTipDlg *m_pTipDlg;
public:
	afx_msg void OnBnClickedButton1();
	CString path;
	afx_msg void OnBnClickedButton2();
};
