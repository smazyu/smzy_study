from typing import List
from queue import Queue
class DancePartner:
    def __init__(self, dance_male_list: List[str], dance_female_list: List[str], dance_num: int):
        self.dance_male_list = dance_male_list
        self.dance_female_list = dance_female_list
        self.dance_num = dance_num
    def into_dance_queue(self):
        dance_man_queue = Queue()
        dance_woman_queue = Queue()
        for man in self.dance_male_list:
            dance_man_queue.put(man)
        for woman in self.dance_female_list:
            dance_woman_queue.put(woman)
        return dance_woman_queue, dance_man_queue
    def dance_outQueue(self, dance_woman_queue, dance_man_queue):
        while not dance_woman_queue.empty():
            name = dance_woman_queue.get()
            print(f'{name} 出队')
        if dance_woman_queue.empty():
            print('女生队列为空')
        while not dance_man_queue.empty():
            name = dance_man_queue.get()
            print(f'{name} 出队')
        if dance_man_queue.empty():
            print('男生队列为空')
dance_list = []
with open('E:\\GitHub\\smzy_study\\作业\\1.txt', 'r', encoding='utf-8') as f:
    for line in f:
        parts = line.strip().split()
        dance_list.append(parts)
female_names = [item[0] for item in dance_list if item[1] == 'F']
male_names = [item[0] for item in dance_list if item[1] == 'M']
print("女性名单:", female_names)
print("男性名单:", male_names)
dance_partner = DancePartner(male_names, female_names, len(dance_list))
dance_woman_queue, dance_man_queue = dance_partner.into_dance_queue()
dance_partner.dance_outQueue(dance_woman_queue, dance_man_queue)
