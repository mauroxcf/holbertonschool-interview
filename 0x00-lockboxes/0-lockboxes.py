#!/usr/bin/python3



def canUnlockAll(boxes):
    print(boxes)
    all_keys = boxes[0] # 1,2
    # aqui guardo el indice
    open_boxes = [0] # 0,1
    i = 1
    while i < len(boxes):
        if i in all_keys:
            if i not in open_boxes:
                all_keys.append(boxes[i])
                open_boxes.append(i)
                i = 0
        i += 1
    print(open_boxes)
    if len(open_boxes) == len(boxes):
        return True
    else:
        return False
