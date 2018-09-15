
// MfcStudyDlg.h : 头文件
//


#pragma once

#include "TipDlg.h"

// CMfcStudyDlg 对话框
class CMfcStudyDlg : public CDialogEx
{
// 构造
public:
	CMfcStudyDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMfcStudyDlg();

// 对话框数据
	enum { IDD = IDD_MFCSTUDY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
