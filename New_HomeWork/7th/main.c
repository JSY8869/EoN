#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DataList
{
	char* bookName;
	char* writer;
	int publicationYear;
	char* publisher;
	char* genre;
	struct DataList* nextList;
};

struct DataList* FileIn(struct DataList* dataStart) {

	struct DataList* loopLiked = dataStart;   //datalist�� ����Ű�� loopliked�����Ϳ� datastart���� �����Ѵ�.(ó���̸� null��)

	char* strInFileName;  //���� ��θ� ���� ������
	FILE* inFile; //infile ���� ������

	strInFileName = "C:/Users/shlee/Desktop/booklist.txt"; //���� ��� ����

	if ((inFile = fopen(strInFileName, "r")) == NULL) { //������ �����µ� �ƹ��͵� ���� ��� 
		printf("��� ���� ���� ����\n");
		exit(1);
	}

	int ibuffer;
	char buffer[4][100];

	while (!feof(inFile)) { //feof: ������ ���� ���������� 1�� �׷��� ������ 0���� ��ȯ

		fscanf(inFile, "%s %s %d %s %s", buffer[0], buffer[1], &ibuffer, buffer[2], buffer[3]); //infile ������ �Է� �ޱ�
		char* out[4];
		for (int i = 0; i < 4; i++) {
			out[i] = malloc(sizeof(char) * (strlen(buffer[i]))); //���� �Ҵ�
			strcpy(out[i], buffer[i]);//���� ������ out�̶�� �迭�� �����ϴ� ����
		}

		struct DataList* newData = malloc(sizeof(struct DataList) * 1); // newdata ��� ������ ����ü ��ŭ�� ������� ���� �Ҵ�
		newData->bookName = out[0]; //������ out�迭�� �����Ѵ�.
		newData->writer = out[1];
		newData->publicationYear = ibuffer;
		newData->publisher = out[2];
		newData->genre = out[3];
		newData->nextList = NULL;

		if (dataStart == NULL) { // datastart�� null ���̸� newdata�� �����ϰ� ,�� datastart ���� loopliked�� �����Ѵ�
			dataStart = newData;
			loopLiked = dataStart;
		}
		else {// datastart�� null���� �ƴϸ� loopliked�� nextlist�� ����Ű���ϰ� �װ��� newdata�� ����Ű�� �Ѵ�.
			loopLiked->nextList = newData;
			loopLiked = loopLiked->nextList;//���� loopliked�� nextlist�� ���Եȴ�.
		}

	}
	fclose(inFile); //������ �ݴ´�.
	printf("File load OK\n");
	return dataStart; //datastart���� ��ȯ�Ѵ�.
}

void FileOut(struct DataList* printNode) {
	char* strOutFileName; //��� ����
	FILE* outFile; //outfile ������

	strOutFileName = "C:/Users/shlee/Desktop/booklist.txt";

	if ((outFile = fopen(strOutFileName, "w")) == NULL) { //outfile �����Ϳ� ������θ� �������� null���̸�
		printf("��� ���� ���� ����\n"); //����
		exit(1);
	}

	while (printNode != NULL) { //datalist����ü�� ����Ű�� printnod�� �����Ͱ� null���϶�����
		if (printNode->nextList == NULL) { //���
			fprintf(outFile, "%s %s %d %s %s", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre);
		}
		else {
			fprintf(outFile, "%s %s %d %s %s\n", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre);
		}
		printNode = printNode->nextList; //printnode�� printnode�� ����Ű��nextlist�� ����
	}


	fclose(outFile); // ���� �ݱ�
	printf("File Save OK\n");
}

void PrintBook(struct DataList* dataStart);

char* In_String() {
	char buffer[100]; //�迭����
	scanf("%s", buffer); //�Է¹ް�
	char* out = malloc(sizeof(char) * (strlen(buffer)));//�Է¹��� ũ�⸸ŭ�� ���� �迭�� �����ϰ�  �װ��� ����Ű�� out�� ����
	strcpy(out, buffer); //buffer�� out���� ����
	return out; //out�� ��ȯ
}

struct DataList* AddBook(struct DataList* dataStart) {
	struct DataList* loopLinkd = dataStart; //datastart���� loopliked�� ����

	printf("�߰��� ������ �Է��ϼ���. \n");
	printf("(������, ����, ���ǿ���, ���ǻ��, �帣 ������ ��� �Է�)\n");
	struct DataList* newData = malloc(sizeof(struct DataList) * 1); //datalist�� ũ�⸸ŭ ���ο� datalist(�����Ҵ�)�� ����Ű�� newdata�� ����
	newData->bookName = In_String();
	newData->writer = In_String();
	scanf("%d", &newData->publicationYear);
	newData->publisher = In_String();
	newData->genre = In_String();;
	newData->nextList = NULL; // �߰��� ���� �Է¹ޱ�(�����͸� Ȱ���Ͽ� ���鱸������ �Է� �ޱ�)

	if (dataStart == NULL) { //datastart�� null���̸� newdata���� ����
		dataStart = newData;
	}
	else {
		while (loopLinkd->nextList != NULL) { //�װ� �ƴϸ� lopplinked�� ����Ű�� nextlist �����Ͱ� null���� �ɶ� ���� �ݺ����� ����
			loopLinkd = loopLinkd->nextList;
		}
		loopLinkd->nextList = newData; //�� �Ŀ� looplinked�� ����Ű�� nextlist�����ʹ� newdata�� �ּҸ� �޴´�.
	}

	return dataStart; //�׸��� datastart������ ���� ��ȯ�Ѵ�.
}
struct DataList* SearchNode(struct DataList* testNode, char* sTest) {
	char sValue[10]; //�迭 ����
	if (testNode == NULL) { //testnode��, looplinked�����Ͱ� null���̸� null�� ��ȯ
		return NULL;
	}
	else {//�װ� �ƴϸ� 
		while (testNode != NULL) { //testnode�����Ͱ� null���϶� ����
			if (strstr(testNode->bookName, sTest) != NULL) { //testnode �� ����Ű�� bookname�����Ͱ� stest�� ����Ű�� ���� ��ġ�Ҷ� �� �ּҰ��� ��ȯ�ϰ� �� ���� null���� �ƴϸ�
				return testNode; //�׶��� testnode �ּҰ��� ��ȯ
			}
			else if (strstr(testNode->writer, sTest) != NULL) {
				return testNode;
			}
			else if (strstr(_itoa(testNode->publicationYear, sValue, 10), sTest) != NULL) {
				return testNode;
			}
			else if (strstr(testNode->publisher, sTest) != NULL) {
				return testNode;
			}
			else if (strstr(testNode->genre, sTest) != NULL) {
				return testNode;
			}
			else {
				testNode = testNode->nextList;
			}
		}
		return NULL;
	}
}

void SearchBook(struct DataList* loopLinkd) {

	printf("�����˻�\n");
	printf("(������, ����, ���ǿ���, ���ǻ��, �帣 �˻�����)\n");
	printf("�˻��� �ܾ �Է��ϼ���: ");
	char* sTest = In_String(); //stest�����Ͱ� string�Լ��� ����Ŵ
	printf("\n");
	printf("-----------------------------------\n");
	struct DataList* printNode; //datalist�������� ����Ű�� printnode������ ����
	int c = 0;
	while (loopLinkd != NULL) {//looplinked�� null���� �϶�����

		printNode = SearchNode(loopLinkd, sTest); //printnode�����ʹ� searchnode�Լ� ����, printnode�����ʹ� �ش� ã�� �ּҰ��� ����ȴ�

		if (printNode == NULL) { //�ּҰ��� null���̸� ��, �˻��� ���� ������ null���� �״� �� ��� break

			break;
		}
		else {//�װ� �ƴϸ� �ش� �ּҰ��� �ش��ϴ� ��� ������ ���
			printf("%s, %s, %d, %s, %s\n", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre);
			loopLinkd = printNode->nextList; //�� �� printnode�� ����Ű�� nextlist�� �ּҰ��� looplink�� ���� �� �ݺ�(nextlist�� null���϶� ����)
		}
		c++; //���� Ű���尡 ������� ���� ���� ���ڸ� ����
	}
	printf("-----------------------------------\n");
	printf("�˻����: �� (%d)�� �Դϴ�.\n", c);
}

void EditBook(struct DataList* dataStart) {
	if (dataStart == NULL) { //datalist����ü�� ����Ű�� datastart�����Ͱ� null���̸� ����
		return;
	}
	PrintBook(dataStart); //�װ� �ƴϸ� printbook ����

	struct DataList* testNode = dataStart; //datalist�� ����Ű�� testnode �����Ϳ� datastart��� �ּҰ� ����
	while (1) {
		printf("\n������ �������� ��Ȯ�� �Է��ϼ���:");
		char* delBookName = In_String(); //delbookname�̶�� �����Ͱ� ������ �������� ���� ���� ����Ű��

		while (testNode != NULL) { //testnode�����Ͱ� null���� �� ���� 
			if (strcmp(testNode->bookName, delBookName) == 0) { //testnode�����Ͱ� ����Ű�� bookname�̶� delbookmame�̶� ������ 0�̹Ƿ� �׷���� break
				break;
			}
			else {//���� ������ testnode�����Ͱ� ����Ű�� nextlist�����͸� testnode�� �����ϰ� testnode�����Ͱ� ����Ű�� bookname�̶� delbookmame�̶� ������ ���� �ݺ�
				testNode = testNode->nextList;
			}
		}
		if (testNode == NULL) { //testnode���� null���̸� ���� ���� ã�� �������Ƿ� testnode�����ʹ� datastart�� ���� �����Ѵ�.
			testNode = dataStart;
			printf("�˻��� �������� �����ϴ�.\n");
		}
		else { //testnode�����Ͱ� null���̾ƴϸ� break
			break;
		}

	}

	printf("������ ����� �����ϼ���(1.������ 2.���� 3.���ǿ��� 4.���ǻ�� 5.�帣) : ");
	int sel; //sel ���� �Է¹ް�
	while (1) {
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			printf("������ ������ �Է� : "); // instring �Լ��� ������ �ش� ������ ��ȯ���ְ� �� ��ȯ�ϴ°��� �ش� �����Ͱ� ����Ű�Ƿ� ���� ����
			testNode->bookName = In_String();
			break;
		case 2:
			printf("������ ���� �Է� : ");
			testNode->writer = In_String();
			break;
		case 3:
			printf("������ ���ǿ��� �Է� : ");
			int year;
			scanf("%d", &year);
			testNode->publicationYear = year;
			break;
		case 4:
			printf("������ ���ǻ�� �Է� : ");
			testNode->publisher = In_String();
			break;
		case 5:
			printf("������ ���ǻ�� �Է� : ");
			testNode->genre = In_String();
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ��Է��ϼ���:");
			continue;
			break;
		}
		break;
	}
	printf("\n�����Ϸ� :"); //�� �� �ش� �����͵��� ����Ű�� �͵��� �����
	printf("%s %s %d %s %s\n", testNode->bookName, testNode->writer, testNode->publicationYear, testNode->publisher, testNode->genre);

}

struct DataList* DeleteBook(struct DataList* dataStart) {
	PrintBook(dataStart); //printbook���� ���� ������� ���

	struct DataList* testNode = dataStart; //datalist����ü�� ����Ű�� testnode�����Ϳ� datastart�ּҰ� ����

	while (1) {
		printf("\n������ �������� ��Ȯ�� �Է��ϼ���:");
		char* delBookName = In_String(); //instring���� delbookname�̶�� �����Ͱ� ����Ű�� ���� �ް�
		while (testNode != NULL) { //testnode���� null���϶����� 
			if (strcmp(testNode->bookName, delBookName) == 0) {//testnode�� ����Ű�� bookname�� ����Ű�� �Ͱ� delbookname�� ����Ű�µ� ������ 0�� ��ȯ�ϰ� �� ��� break
				break;
			}
			else {
				testNode = testNode->nextList; //���� ������� testnode�� ����Ű�� nextlist�� �ּҰ��� testnode�� ����
			}
		}
		if (testNode == NULL) { //testnode���� null �̸� ã�� ���� ����̹Ƿ� datastart�� �ٽ� testnode�� ������(���󺹱�) break
			testNode = dataStart;
			printf("�˻��� �������� �����ϴ�.\n");
		}
		else {
			break;
		}
	}
	struct DataList* loopNode = dataStart; //datalist�� ����Ű�� loopnode�����Ϳ� datastart�ּҰ� ����
	if (testNode == dataStart) { //testnode���̶� datastart���̶� ������
		dataStart = dataStart->nextList; //datastart�� ����Ű�� nextlist���� datastart�� ������ 
		free(testNode); //testnode�� ����Ű�� �� free
	}
	else { //testnode�� datastart�� �ٸ���
		while (loopNode != NULL) { //loopnode�� null���϶� ����
			if (loopNode->nextList == testNode) { //loopnode�� ����Ű�� nextlist���� testnode�� ������ break
				break;
			}
			else {//loopnode�� ����Ű�� nextlist���� testnode�� �ٸ���
				loopNode = loopNode->nextList; // loopnode�� loopnode�� ����Ű�� nextlist �� ���� �� while �� �ݺ� 
			}
		}
		loopNode->nextList = testNode->nextList; //loopnode �� ����Ű�� nextlist�� testnode�� ����Ű�� nextlist �� ������
		free(testNode); //testnode �� ����Ű�°� free
	}
	printf("���� ���� �Ǿ����ϴ�.\n");
	return dataStart; //datastart ��ȯ
}

void PrintBook(struct DataList* dataStart) {
	struct DataList* loopLinkd = dataStart; //datalist����ÿ�� ����Ű�� looplink�����Ϳ� datastart�ּҰ��� ����
	printf("\n������ ���� ���ǿ��� ���ǻ�� �帣\n");
	printf("-----------------------------------\n");
	while (loopLinkd != NULL) { //looplinked���� null���� �ɶ����� ������ ���
		printf("%s %s %d %s %s\n", loopLinkd->bookName, loopLinkd->writer, loopLinkd->publicationYear, loopLinkd->publisher, loopLinkd->genre);
		loopLinkd = loopLinkd->nextList; //�� �� looplinked�� ����Ű�� nextlist �������� �ּҰ��� looplinked�� ���� �� while�� �ݺ�
	}
	printf("-----------------------------------\n");
}
void menu(struct DataList* dataStart) {

	int sel;
	while (1) {
		printf("=======================\n");
		printf("1.���� �߰� \n");
		printf("2.���� �˻� \n");
		printf("3.���� ���� ���� \n");
		printf("4.���� ���� \n");
		printf("5.���� �� ���� ��� ��� \n");
		printf("6.���� \n");
		printf("7.���α׷� ������(�ڵ�����) \n");
		printf("�Է�: ");
		scanf("%d", &sel);
		printf("\n");
		switch (sel)
		{
		case 1:
			printf("1.���� �߰� \n");
			dataStart = AddBook(dataStart); //addbook ����
			break;
		case 2:
			printf("2.���� �˻� \n");
			SearchBook(dataStart); //searchbook ����
			break;
		case 3:
			printf("3.���� ���� ���� \n");
			EditBook(dataStart); //editbook ����
			break;
		case 4:
			printf("4.���� ���� \n");
			dataStart = DeleteBook(dataStart); //deletebook ����
			break;
		case 5:
			printf("5.���� �� ���� ��� ��� \n"); 
			PrintBook(dataStart); //printbook ����
			break;
		case 6:
			printf("6.���� \n"); 
			FileOut(dataStart); //fileout ����
			break;
		case 7:
			printf("7.���α׷� ������(�ڵ�����) \n");
			FileOut(dataStart); //fileout ����
			return;
			break;
		default:
			printf("�ٽ��Է��ϼ���.\n");
			break;
		}
		printf("\n");
	}
}

int main() {

	struct DataList* dataStart = NULL; //datastart��� ������ datalist ��� ����ü�� �ּҸ� �����ϴµ� null���� �����Ѵ�.
	dataStart = FileIn(dataStart);     //null���� datastart�� fileind�� ������ ��ȯ�� datastart���� datastart�� �����Ѵ�.
	menu(dataStart); //�޴��Լ��� ��ȯ ���� datastart���� �����Ѵ�.

	return 0;
}