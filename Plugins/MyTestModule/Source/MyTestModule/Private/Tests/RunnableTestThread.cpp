#include "MyTestModulePrivatePCH.h"
#include "RunnableThread.h"



/**
 * œﬂ≥Ã≤‚ ‘demo
 */

class FRunnableTestThread :public FRunnable
{
public:
	FRunnableTestThread(int16 _Index) :Index(_Index) {}
	virtual bool Init()override
	{
		UE_LOG(TestLog, Log, TEXT("Thread %d Init"), Index);
		return true;
	}

	virtual uint32 Run()override
	{
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:1"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:2"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:3"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		return 0;
	}

	/**
	* Stops the runnable object.
	*
	* This is called if a thread is requested to terminate early.
	* @see Init, Run, Exit
	*/
	virtual void Stop()override
	{
	}

	/**
	* Exits the runnable object.
	*
	* Called in the context of the aggregating thread to perform any cleanup.
	* @see Init, Run, Stop
	*/
	virtual void Exit() override
	{
		UE_LOG(TestLog, Log, TEXT("Thread %d Exit"), Index);
	}

private:
	int16 Index;

};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFRunnableTest,"MyTest.PublicTest.RunnableTest",
	EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)

bool FFRunnableTest::RunTest(const FString& Parameters)
{
	FRunnableThread::Create(new FRunnableTestThread(0), TEXT("TestThread0"));
	FRunnableThread::Create(new FRunnableTestThread(1), TEXT("TestThread1"));
	FRunnableThread::Create(new FRunnableTestThread(2), TEXT("TestThread2"));
	return true;
}