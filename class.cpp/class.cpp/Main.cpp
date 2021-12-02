#include "seqlist.h"

int main()
{
	SeqList list;
	SeqListInit(&list);
	ElemType item;
	size_t pos;
	int flag = 0;
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
//		printf("*  [16]front          [17]back       *\n");   ��δʵ��
//		printf("*  [18]binary_find    [19]erase_all  *\n");
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
				SeqListPushBack(&list, item);
			}
			printf("β������ɹ�\n");
			break;
		case 2://ͷ��
			printf("�������������ݣ���-1����\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			printf("ͷ������ɹ�\n");
			break;
		case 3://��ʾ��
			SeqListShow(&list);
			break;
		case 4://βɾ
			SeqListPopBack(&list);
			printf("β��ɾ�����ݳɹ�\n");
			break;
		case 5://ͷɾ
			SeqListPopFront(&list);
			printf("ͷ��ɾ�����ݳɹ�\n");
			break;
		case 6://��λ�ò���
			printf("����������λ��");
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
		case 7://��ֵ����
			printf("������Ҫ���������");
			scanf("%d", &item);
			SeqListSort(&list);
			flag = SeqListInsertbyval(&list, item);
			if (flag){
				printf("��ֵ����ɹ�\n");
			}
			else{
				printf("��ֵ����ʧ��\n");
			}
			break;
		case 8://��λ��ɾ��
			printf("��������Ҫɾ����λ��\n");
			scanf("%d", &pos);
			SeqListEarsebypos(&list, pos);
			printf("��λ��ɾ�����ݳɹ�");
			break;
		case 9://��ֵɾ��
			printf("������Ҫɾ��������\n");
			scanf("%d", &item);
			SeqListErasebyval(&list, item);
			printf("ɾ�����ݳɹ�\n");
			break;
		case 10://����
			printf("����������ҵ�����\n");
			scanf("%d", &item);
			pos=SeqListFind(&list, item);
			if (pos==-1){
				printf("���ݲ���ʧ�ܣ�������\n");
			}
			else{
				printf("���ҳɹ�\n");
			}
			break;
		case 11://��
			printf("SeqList Length %d", SeqListLength(&list));
			break;
		case 12://������
			printf("SeqList Capaity:%d", SeqListCapacity(&list));
			break;
		case 13://����
			SeqListSort(&list);
			printf("˳�������ɹ�");
			break;
		case 14://��ת��
			SeqListReverse(&list);
			printf("ת�����\n");
			break;
		case 15://�����
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