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
		printf("��ѡ��>");
		scanf("%d", &select);
		if (select == 0){
			break;
		}
		switch (select)
		{
		case 1://β��
			printf("��������������,��-1����\n");
			while (scanf("%d", &item), item != -1)
			{
				DCListNodePushBack(&list, item);
			}
			printf("β������ɹ�\n");
			break;
			case 2://ͷ��
				printf("�������������ݣ���-1����\n");
		     	while (scanf("%d", &item), item != -1)
				{
					DCListPushFront(&list, item);
				}
				printf("ͷ������ɹ�\n");
				break;
			case 3://��ʾ��
				DCListShow(list);
				break;
			case 4://βɾ
				DCListPopBack(&list);
				printf("β��ɾ�����ݳɹ�\n");
				break;
			case 5://ͷɾ
				DCListPopFront(&list);
				printf("ͷ��ɾ�����ݳɹ�\n");
				break;
			//case 6://��λ�ò���
			//	printf("����������λ��");
			//	scanf("%d", &pos);
			//	printf("������Ҫ���������");
			//	scanf("%d", &item);
			//	//flag = SListInsertbypos(&list, pos, item);
			//	if (flag){
			//		printf("����ɹ�\n");
			//	}
			//	else{
			//		printf("����ʧ��\n");
			//	}
			//	break;
			case 7://��ֵ����
				printf("������Ҫ���������");
				scanf("%d", &item);
				DCListSort(list);
				DCListInsertbyval(list, item);

				printf("��ֵ����ɹ�\n");

				break;
			//	//case 8://��λ��ɾ��
			//	//	printf("��������Ҫɾ����λ��\n");
			//	//	scanf("%d", &pos);
			//	//	//SListEarsebypos(&list, pos);
			//	//	printf("��λ��ɾ�����ݳɹ�");
			//	//	break;
			case 9://��ֵɾ��
				printf("������Ҫɾ��������\n");
				scanf("%d", &item);
				DCListErasebyval(list, item);
				printf("ɾ�����ݳɹ�\n");
				break;
			case 10://����
				printf("����������ҵ�����\n");
				scanf("%d", &item);
				p=DCListFind(list, item);
				if (p == NULL){
					printf("����ʧ��\n");
				}
				else{
					printf("���ҳɹ�\n");
				}
				break;
			case 11://��
				printf("SeqList Length %d", DCListLength(&list));
				break;
			//case 12://������
			//	//printf("SeqList Capaity:%d", SeqListCapacity(&list));
			//	break;
			case 13://����
				DCListSort(list);
				printf("˳�������ɹ�");
				break;
			case 14://��ת��
				DCListReverse(list);
				printf("ת�����\n");
				break;
			case 15://�����
				DCListClear(&list);
				break;
			case 16:
				printf("��ͷԪ��Ϊ��%d\n", DCListFront(list));
				break;
			case 17:
				printf("��βԪ��Ϊ��%d\n", DCListBack(list));
		default:
			printf("�����������������\n");
			break;
		}
	}
	DCListDestroy(&list);
	system("pause");
	return 0;
}