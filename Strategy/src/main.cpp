#include <iostream>
#include "context.h"
#include "strategys.h"

using namespace std;


/**
 * Демонстрация применения конкретной стратегии
 * через вызовы методов контекста
 */
void StrategyDemo(MiniLogger& logger) {
	logger.Debug("This debug message!");
    logger.Info("This info message!");
	logger.Warning("This warning message!");
	logger.Error("This error message!");
	logger.Fatal("This fatal message!");	
}


/**
 * Примеры использования конкретных стратегий 
 */
int main(int argc, char **argv)
{
	/**
	 * Демонстрация конкретной стратегии StdOutMinimal 
	 */
	MiniLogger stdOutMinimal(new StdOutMinimal);	
	StrategyDemo(stdOutMinimal);					

	/**
	 * Демонстация конкретной стратегии StdOutExtended
	 */
	MiniLogger fileOutMinimal(new FileOutMinimal("log.txt"));
	StrategyDemo(fileOutMinimal);

	return 0;
}
