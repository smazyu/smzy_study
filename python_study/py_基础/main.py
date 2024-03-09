from multiprocessing import Process
import os
import time
start = time.time()
list = []
def get_request(url):
    print('我是绑定给子进程的一组任务',url, os.getppid())
    # 执行访问操作
    time.sleep(2)
if __name__ == '__main__':
    print('主进程开始运行主进程id', os.getpid())
    urls = ['www.1.com','www.2.com','www.3.com']
    for url in urls:
        p = Process(target = get_request,args = (url,))
        # 创建子进程
        list.append(p)
        p.start()
    for pp in list:
        pp.join()
    print('主进程执行结束',time.time() - start)