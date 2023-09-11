#ifndef UNTITLED_WORKERTHREAD_H
#define UNTITLED_WORKERTHREAD_H
#include "SharedPreferences.h"
#include <mutex>  //???? 처음보네

class WorkerThread {
public:
    void play();
private:
    void readWorker();
    void writeWorker(int value);
    std::mutex mu;
    std::vector<SharedPreferences*> answers;
};

#endif //UNTITLED_WORKERTHREAD_H
