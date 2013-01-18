// FileTimeNewDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CFileTimeNewDlg 对话框
class CFileTimeNewDlg : public CDialog
{
// 构造
public:
	CFileTimeNewDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FILETIMENEW_DIALOG };

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
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnClose();
public:
	afx_msg void OnDestroy();
	//CEdit m_visit;
	//CEdit m_write;
	//CEdit m_creation;
public:
	afx_msg void OnBnClickedOpen();


	CEdit m_path;

private:
	CString m_FileName;

public:
	CString m_strPath;
	CString m_strVisit;
	CEdit m_visit;
	CEdit m_write;
	CString m_strWrite;
	CEdit m_create;
	CString m_strCreate;
public:
	afx_msg void OnBnClickedSave();
	CTime m_wTime;
	CTime m_cTime;
public:
	afx_msg void OnBnClickedReadme();
};
