#include "seqlist.h"

int main()
{
	SeqList list;
	SeqListInit(&list);
	ElemType item;
	int pos;
	int flag = 0;
	int select = 1;
	while (select){
		printf("*************************************\n");
		printf("*  [1]push_back       [2]push_front  *\n");
		printf("*  [3]show_list       [0]quit_system *\n");
		printf("*  [4]pop_back        [5]pop_front   *\n");
		printf("*  [6]insert_pos      [7]insert_val  *\n");
		printf("*  [8]earse_pos       [9]earse_val   *\n");
		printf("*  [10]find           [11]length     *\n");
		printf("*  [12]capacity       [13]sort       *\n");
		printf("*  [14]reverse        [15]clear      *\n");
		printf("*************************************\n");
		printf("��ѡ��>");
		scanf("%d", &select);
		if (select == 0){
			break;
		}
		switch (select)
		{
		case 1:
			printf("��������������,��-1����\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&list, item);
			}
			printf("β������ɹ�\n");
			break;
		case 2:
			printf("�������������ݣ���-1����\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			printf("ͷ������ɹ�\n");
			break;
		case 3:
			SeqListShow(&list);
			break;
		case 4:
			SeqListPopBack(&list);
			break;
		case 6:
			printf("��������������");
			scanf("%d", &pos);
			printf("������Ҫ���������");
				scanf("%d", &item);
				flag = SeqListInsertbypos(&list, pos, item);
				if (flag){
					printf("����ɹ�\n");
				}
				else{
					printf("����ʧ��\n");
				}
			break;
		case 11:
			printf("SeqList Length %d", SeqListLength(&list));
			break;
		case 13:
			SeqListSort(&list);
			printf("˳�������ɹ�");
			break;
		case 15:
			SeqLIistClear(&list);
			break;
		default:
			printf("�����������������\n");
			break;
		}
		system("pause");
	    system("cls");
	}
	SeqListDestroy(&list);
	return 0;
}