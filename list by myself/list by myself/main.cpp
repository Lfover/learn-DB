#include "dclist.h"

int main(){

	DCList list;
	DCListInit(&list);
	DCListNode *p = NULL;
	int select = 1;
	int item;
	while (select){
		printf("*************************************\n");
		printf("*  [1]push_back       [2]push_front  *\n");
		printf("*  [3]show_list       [0]quenit_system *\n");
		printf("*  [4]pop_back        [5]pop_front   *\n");
		printf("*  [6]insert_pos      [7]insert_val  *\n");
		printf("*  [8]erase_pos       [9]erase_val   *\n");
		printf("*  [10]find           [11]length     *\n");
		printf("*  [12]capacity       [13]sort       *\n");
		printf("*  [14]reverse        [15]clear      *\n");
		printf("*************************************\n");
		printf("请选择：>");
		scanf("%d", &select);
		if (select == 0){
			break;
		}
		switch (select)
		{
		case 1://尾插
			printf("请输入插入的数据,以-1结束\n");
			while (scanf("%d", &item), item != -1)
			{
				DCListNodePushBack(&list, item);
			}
			printf("尾部插入成功\n");
			break;
			case 2://头插
				printf("请输入插入的数据，以-1结束\n");
		     	while (scanf("%d", &item), item != -1)
				{
					DCListPushFront(&list, item);
				}
				printf("头部插入成功\n");
				break;
			case 3://显示表
				DCListShow(list);
				break;
			case 4://尾删
				DCListPopBack(&list);
				printf("尾部删除数据成功\n");
				break;
			case 5://头删
				DCListPopFront(&list);
				printf("头部删除数据成功\n");
				break;
			//case 6://按位置插入
			//	printf("请输入插入的位置");
			//	scanf("%d", &pos);
			//	printf("请输入要插入的数字");
			//	scanf("%d", &item);
			//	//flag = SListInsertbypos(&list, pos, item);
			//	if (flag){
			//		printf("插入成功\n");
			//	}
			//	else{
			//		printf("插入失败\n");
			//	}
			//	break;
			case 7://按值插入
				printf("请输入要插入的数字");
				scanf("%d", &item);
				DCListSort(list);
				DCListInsertbyval(list, item);

				printf("按值插入成功\n");

				break;
			//	//case 8://按位置删除
			//	//	printf("请输入你要删除的位置\n");
			//	//	scanf("%d", &pos);
			//	//	//SListEarsebypos(&list, pos);
			//	//	printf("按位置删除数据成功");
			//	//	break;
			case 9://按值删除
				printf("请输入要删除的数据\n");
				scanf("%d", &item);
				DCListErasebyval(list, item);
				printf("删除数据成功\n");
				break;
			case 10://查找
				printf("输入你想查找的数据\n");
				scanf("%d", &item);
				p=DCListFind(list, item);
				if (p == NULL){
					printf("查找失败\n");
				}
				else{
					printf("查找成功\n");
				}
				break;
			case 11://表长
				printf("SeqList Length %d", DCListLength(&list));
				break;
			//case 12://表容量
			//	//printf("SeqList Capaity:%d", SeqListCapacity(&list));
			//	break;
			case 13://排序
				DCListSort(list);
				printf("顺序表排序成功");
				break;
			case 14://反转表
				DCListReverse(list);
				printf("转置完成\n");
				break;
			case 15://清除表
				DCListClear(&list);
				break;
			case 16:
				printf("表头元素为：%d\n", DCListFront(list));
				break;
			case 17:
				printf("表尾元素为：%d\n", DCListBack(list));
		default:
			printf("命令出错，请重新输入\n");
			break;
		}
	}
	DCListDestroy(&list);
	system("pause");
	return 0;
}