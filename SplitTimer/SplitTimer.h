#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <functional>

namespace SplitTimer
{
	typedef std::function<void(std::string, float)> splitFunc_t;

	const extern splitFunc_t defaultSplitPrint;
	const extern splitFunc_t defaultSplitLogToFile;

	class Timer
	{
	public:
		Timer();
		void reset();
		void setOutputEnabled(bool enabled);
		float split();
		float split(std::string label, splitFunc_t printFn = defaultSplitPrint);
		float elapsedTime();
		float elapsedTime(std::string label, splitFunc_t printFn = defaultSplitPrint);
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> splitTime;
		std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
		bool enableOutput;
	};
}