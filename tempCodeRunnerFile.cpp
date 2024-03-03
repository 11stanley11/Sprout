 if(!flag) {
                    node -> next = NULL;
                    head = node;
                    tail = node;
                    flag = true;
                }else if(ppl[id] == -1 || group_tail[ppl[id]] == NULL) {
                    node -> next = NULL;
                    tail -> next = node;
                    tail = node;
                }else{
                    node -> next = group_tail[ppl[id]] -> next;
                    group_tail[ppl[id]] -> next = node;
                }