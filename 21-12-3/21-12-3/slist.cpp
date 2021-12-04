#include "slist.h"

int main()
{
	SList list;
	SListInit(&list);
	SListNode *p = NULL;
	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while (select){
		printf("*************************************\n");
		printf("*  [1]push_back       [2]push_front  *\n");
		printf("*  [3]show_list       [0]quit_system *\n");
		printf("*  [4]pop_back        [5]pop_front   *\n");
		printf("*  [6]insert_pos      [7]insert_val  *\n");
		printf("*  [8]erase_pos       [9]erase_val   *\n");
		printf("*  [10]find           [11]length     *\n");
		printf("*  [12]capacity       [13]sort       *\n");
		printf("*  [14]reverse        [15]clear      *\n");
		//		printf("*  [16]front          [17]back       *\n");   还未实现
		//		printf("*  [18]binary_find    [19]erase_all  *\n");
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
				SListPushBack(&list, item);
			}
			printf("尾部插入成功\n");
			break;
		case 2://头插
			printf("请输入插入的数据，以-1结束\n");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&list, item);
			}
			printf("头部插入成功\n");
			break;
		case 3://显示表
			SListShow(&list);
			break;
		case 4://尾删
			SListPopBack(&list);
			printf("尾部删除数据成功\n");
			break;
		case 5://头删
			SListPopFront(&list);
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
			SListSort(&list);
			SListInsertbyval(&list, item);
		
				printf("按值插入成功\n");
		
			break;
		//case 8://按位置删除
		//	printf("请输入你要删除的位置\n");
		//	scanf("%d", &pos);
		//	//SListEarsebypos(&list, pos);
		//	printf("按位置删除数据成功");
		//	break;
		case 9://按值删除
			printf("请输入要删除的数据\n");
			scanf("%d", &item);
			SListErasebyval(&list, item);
			printf("删除数据成功\n");
			break;
		case 10://查找
			printf("输入你想查找的数据\n");
			scanf("%d", &item);
			SListFind(list, item);
		
				printf("查找成功\n");
			
			break;
		case 11://表长
			printf("SeqList Length %d", SListLength(&list));
			break;
		case 12://表容量
			//printf("SeqList Capaity:%d", SeqListCapacity(&list));
			break;
		case 13://排序
			SListSort(&list);
			printf("顺序表排序成功");
			break;
		case 14://反转表
			SListReverse(&list);
			printf("转置完成\n");
			break;
		case 15://清除表
			SListClear(&list);
			break;
		default:
			printf("命令出错，请重新输入\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SListDestory(&list);
	return 0;

}