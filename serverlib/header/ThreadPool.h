/*
	author: Macro Gu
	email: macrogu@qq.com
	QQ: 877188891
*/

#pragma once

#include <queue>
#include <vector>
#include <condition_variable>  
#include <mutex>
#include <thread>
#include <functional>
#include <stdint.h>
#include "defines.h"

class Task
{
    public: 
        Task(std::function<void (void*)> callBackFun, void* arg); // pass a free function pointer
        ~Task();
        void ExecuteTask();
    private:
		std::function<void (void*)> mFTaskRunCB;
        void* m_arg;
};


class ThreadPool
{
public:

        ThreadPool();
        ~ThreadPool();

        bool Start();

		// ���task ���̳߳�ִ�ж���
        bool AddTask(Task *task);

		// �����߳�ִ������ǰ�Ļص�
        void SetThreadCallBackAtStart(std::function<void(void)> startedCB);
        
		void SetTaskSizeLimit(int size);

        bool SetWorkThreadNums(int threadNums);

private:

	// �ͷ������̳߳���Դ
	void ReleaseThreadPool();

	// ִ���߳� 
	void ExecuteThread();

	// the thread's call back function
	void ThreadCallBackFunc(void* arg);		

private:

		// ȫ�������̵߳����� 
		uint8_t WorkThreadsNums;
		
		// �̳߳ع���Ļ�����
		std::mutex ThreadsSharedMutex;

		// �̳߳ع������������
		std::condition_variable_any ThreadSharedCondVar;

		// �̳߳�ȫ���Ĺ����߳�
		std::vector<std::thread> AllWorkThreads;

		// ��Ҫ�̳߳ش�����������
        std::queue<Task *> TasksQueue;

		// ��������� �߳�ִ������ǰ�Ļص�
		std::function<void(void)> CallBackFunAtStart;
		
		// ture: �����̳߳���������  false: ���� �̳߳�ֹͣ����
		bool bThreadPoolRunning;

		// �̳߳� ��ͬʱ�������� task ������
        uint32_t TasksNumsLimitSize;
};
