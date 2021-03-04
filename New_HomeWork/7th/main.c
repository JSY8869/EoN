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

	struct DataList* loopLiked = dataStart;   //datalist를 가리키는 loopliked포인터에 datastart값을 대입한다.(처음이면 null값)

	char* strInFileName;  //파일 경로를 위한 포인터
	FILE* inFile; //infile 파일 포인터

	strInFileName = "C:/Users/shlee/Desktop/booklist.txt"; //파일 경로 지정

	if ((inFile = fopen(strInFileName, "r")) == NULL) { //파일을 열었는데 아무것도 없을 경우 
		printf("출력 파일 열기 실패\n");
		exit(1);
	}

	int ibuffer;
	char buffer[4][100];

	while (!feof(inFile)) { //feof: 파일의 끝에 도달했으면 1을 그렇지 않으면 0값을 반환

		fscanf(inFile, "%s %s %d %s %s", buffer[0], buffer[1], &ibuffer, buffer[2], buffer[3]); //infile 내용을 입력 받기
		char* out[4];
		for (int i = 0; i < 4; i++) {
			out[i] = malloc(sizeof(char) * (strlen(buffer[i]))); //동적 할당
			strcpy(out[i], buffer[i]);//원래 파일을 out이라는 배열에 복사하는 과정
		}

		struct DataList* newData = malloc(sizeof(struct DataList) * 1); // newdata 라는 변수가 구조체 만큼의 사이즈로 동적 할당
		newData->bookName = out[0]; //복사한 out배열을 대입한다.
		newData->writer = out[1];
		newData->publicationYear = ibuffer;
		newData->publisher = out[2];
		newData->genre = out[3];
		newData->nextList = NULL;

		if (dataStart == NULL) { // datastart가 null 값이면 newdata를 대입하고 ,그 datastart 값을 loopliked에 대입한다
			dataStart = newData;
			loopLiked = dataStart;
		}
		else {// datastart가 null값이 아니면 loopliked가 nextlist를 가리키게하고 그것이 newdata를 가리키게 한다.
			loopLiked->nextList = newData;
			loopLiked = loopLiked->nextList;//그후 loopliked에 nextlist가 대입된다.
		}

	}
	fclose(inFile); //파일을 닫는다.
	printf("File load OK\n");
	return dataStart; //datastart값을 반환한다.
}

void FileOut(struct DataList* printNode) {
	char* strOutFileName; //경로 지정
	FILE* outFile; //outfile 포인터

	strOutFileName = "C:/Users/shlee/Desktop/booklist.txt";

	if ((outFile = fopen(strOutFileName, "w")) == NULL) { //outfile 포인터에 지정경로를 열었을때 null값이면
		printf("출력 파일 열기 실패\n"); //실패
		exit(1);
	}

	while (printNode != NULL) { //datalist구조체를 가리키는 printnodㄷ 포인터가 null값일때까지
		if (printNode->nextList == NULL) { //출력
			fprintf(outFile, "%s %s %d %s %s", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre);
		}
		else {
			fprintf(outFile, "%s %s %d %s %s\n", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre);
		}
		printNode = printNode->nextList; //printnode에 printnode가 가리키는nextlist값 대입
	}


	fclose(outFile); // 파일 닫기
	printf("File Save OK\n");
}

void PrintBook(struct DataList* dataStart);

char* In_String() {
	char buffer[100]; //배열생성
	scanf("%s", buffer); //입력받고
	char* out = malloc(sizeof(char) * (strlen(buffer)));//입력받은 크기만큼의 동적 배열을 생성하고  그것을 가리키는 out을 만듬
	strcpy(out, buffer); //buffer을 out으로 복사
	return out; //out을 반환
}

struct DataList* AddBook(struct DataList* dataStart) {
	struct DataList* loopLinkd = dataStart; //datastart값을 loopliked에 대입

	printf("추가할 도서를 입력하세요. \n");
	printf("(도서명, 저자, 출판연도, 출판사명, 장르 순으로 띄어 입력)\n");
	struct DataList* newData = malloc(sizeof(struct DataList) * 1); //datalist의 크기만큼 새로운 datalist(동적할당)를 가리키는 newdata를 선언
	newData->bookName = In_String();
	newData->writer = In_String();
	scanf("%d", &newData->publicationYear);
	newData->publisher = In_String();
	newData->genre = In_String();;
	newData->nextList = NULL; // 추가할 도서 입력받기(포인터를 활용하여 공백구분으로 입력 받기)

	if (dataStart == NULL) { //datastart가 null값이면 newdata값을 대입
		dataStart = newData;
	}
	else {
		while (loopLinkd->nextList != NULL) { //그게 아니면 lopplinked가 가리키는 nextlist 포인터가 null값이 될때 까지 반복으로 대입
			loopLinkd = loopLinkd->nextList;
		}
		loopLinkd->nextList = newData; //그 후에 looplinked가 가리키는 nextlist포인터는 newdata의 주소를 받는다.
	}

	return dataStart; //그리고 datastart포인터 값을 반환한다.
}
struct DataList* SearchNode(struct DataList* testNode, char* sTest) {
	char sValue[10]; //배열 선언
	if (testNode == NULL) { //testnode즉, looplinked포인터가 null값이면 null값 반환
		return NULL;
	}
	else {//그게 아니면 
		while (testNode != NULL) { //testnode포인터가 null값일때 까지
			if (strstr(testNode->bookName, sTest) != NULL) { //testnode 가 가리키는 bookname포인터가 stest가 가리키는 값과 일치할때 그 주소값을 반환하고 그 값이 null값이 아니면
				return testNode; //그때의 testnode 주소값을 반환
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

	printf("도서검색\n");
	printf("(도서명, 저자, 출판연도, 출판사명, 장르 검색가능)\n");
	printf("검색할 단어를 입력하세요: ");
	char* sTest = In_String(); //stest포인터가 string함수를 가리킴
	printf("\n");
	printf("-----------------------------------\n");
	struct DataList* printNode; //datalist구초제를 가리키는 printnode포인터 선언
	int c = 0;
	while (loopLinkd != NULL) {//looplinked가 null값이 일때까지

		printNode = SearchNode(loopLinkd, sTest); //printnode포인터는 searchnode함수 실행, printnode포인터는 해당 찾은 주소값이 저장된다

		if (printNode == NULL) { //주소값이 null값이면 즉, 검색한 값이 없으면 null값일 테니 그 경우 break

			break;
		}
		else {//그게 아니면 해당 주소값에 해당하는 모든 정보를 출력
			printf("%s, %s, %d, %s, %s\n", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre);
			loopLinkd = printNode->nextList; //그 후 printnode가 가리키는 nextlist의 주소값을 looplink에 저장 후 반복(nextlist가 null값일때 까지)
		}
		c++; //같은 키워드가 몇개인지를 세기 위해 숫자를 증가
	}
	printf("-----------------------------------\n");
	printf("검색결과: 총 (%d)건 입니다.\n", c);
}

void EditBook(struct DataList* dataStart) {
	if (dataStart == NULL) { //datalist구조체를 가리키는 datastart포인터가 null값이면 종료
		return;
	}
	PrintBook(dataStart); //그게 아니면 printbook 실행

	struct DataList* testNode = dataStart; //datalist를 가리키는 testnode 포인터에 datastart라는 주소값 대입
	while (1) {
		printf("\n수정할 도서명을 정확히 입력하세요:");
		char* delBookName = In_String(); //delbookname이라는 포인터가 수정할 도서명을 받은 것을 가리키고

		while (testNode != NULL) { //testnode포인터가 null값일 때 까지 
			if (strcmp(testNode->bookName, delBookName) == 0) { //testnode포인터가 가리키는 bookname이랑 delbookmame이랑 같으면 0이므로 그런경우 break
				break;
			}
			else {//같지 않으면 testnode포인터가 가리키는 nextlist포인터를 testnode에 저장하고 testnode포인터가 가리키는 bookname이랑 delbookmame이랑 같을때 까지 반복
				testNode = testNode->nextList;
			}
		}
		if (testNode == NULL) { //testnode값이 null값이면 같은 것을 찾지 못했으므로 testnode포인터는 datastart의 값을 저장한다.
			testNode = dataStart;
			printf("검색된 도서명이 없습니다.\n");
		}
		else { //testnode포인터가 null값이아니면 break
			break;
		}

	}

	printf("수정할 목록을 선택하세요(1.도서명 2.저자 3.출판연도 4.출판사명 5.장르) : ");
	int sel; //sel 값을 입력받고
	while (1) {
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			printf("변경할 도서명 입력 : "); // instring 함수로 선택한 해당 것으로 반환해주고 그 반환하는것을 해당 포인터가 가리키므로 수정 성공
			testNode->bookName = In_String();
			break;
		case 2:
			printf("변경할 저자 입력 : ");
			testNode->writer = In_String();
			break;
		case 3:
			printf("변경할 출판연도 입력 : ");
			int year;
			scanf("%d", &year);
			testNode->publicationYear = year;
			break;
		case 4:
			printf("변경할 출판사명 입력 : ");
			testNode->publisher = In_String();
			break;
		case 5:
			printf("변경할 출판사명 입력 : ");
			testNode->genre = In_String();
			break;
		default:
			printf("잘못된 입력입니다. 다시입력하세요:");
			continue;
			break;
		}
		break;
	}
	printf("\n수정완료 :"); //그 후 해당 포인터들이 가리키는 것들을 출력함
	printf("%s %s %d %s %s\n", testNode->bookName, testNode->writer, testNode->publicationYear, testNode->publisher, testNode->genre);

}

struct DataList* DeleteBook(struct DataList* dataStart) {
	PrintBook(dataStart); //printbook으로 현재 도서목록 출력

	struct DataList* testNode = dataStart; //datalist구조체를 가리키는 testnode포인터에 datastart주소값 대입

	while (1) {
		printf("\n삭제랑 도서명을 정확히 입력하세요:");
		char* delBookName = In_String(); //instring으로 delbookname이라는 포인터가 가리키는 값을 받고
		while (testNode != NULL) { //testnode값이 null값일때까지 
			if (strcmp(testNode->bookName, delBookName) == 0) {//testnode가 가리키는 bookname이 가리키는 것과 delbookname이 가리키는데 같으면 0을 반환하고 그 경우 break
				break;
			}
			else {
				testNode = testNode->nextList; //같지 않을경우 testnode가 가리키는 nextlist의 주소값을 testnode에 저장
			}
		}
		if (testNode == NULL) { //testnode값이 null 이면 찾지 못한 경우이므로 datastart를 다시 testnode에 저장후(원상복귀) break
			testNode = dataStart;
			printf("검색된 도서명이 없습니다.\n");
		}
		else {
			break;
		}
	}
	struct DataList* loopNode = dataStart; //datalist를 가리키는 loopnode포인터에 datastart주소값 저장
	if (testNode == dataStart) { //testnode값이랑 datastart값이랑 같으면
		dataStart = dataStart->nextList; //datastart가 가리키는 nextlist값을 datastart에 저장후 
		free(testNode); //testnode가 가리키는 것 free
	}
	else { //testnode랑 datastart랑 다르면
		while (loopNode != NULL) { //loopnode가 null값일때 까지
			if (loopNode->nextList == testNode) { //loopnode가 가리키는 nextlist값이 testnode랑 같으면 break
				break;
			}
			else {//loopnode가 가리키는 nextlist값이 testnode랑 다르면
				loopNode = loopNode->nextList; // loopnode에 loopnode가 가리키는 nextlist 값 대입 후 while 문 반복 
			}
		}
		loopNode->nextList = testNode->nextList; //loopnode 가 가르키는 nextlist에 testnode가 가르키는 nextlist 값 대입후
		free(testNode); //testnode 가 가르키는것 free
	}
	printf("정상 삭제 되었습니다.\n");
	return dataStart; //datastart 반환
}

void PrintBook(struct DataList* dataStart) {
	struct DataList* loopLinkd = dataStart; //datalist구조첼르 가리키는 looplink포인터에 datastart주소값을 대입
	printf("\n도서명 저자 출판연도 출판사명 장르\n");
	printf("-----------------------------------\n");
	while (loopLinkd != NULL) { //looplinked값이 null값이 될때까지 정보들 출력
		printf("%s %s %d %s %s\n", loopLinkd->bookName, loopLinkd->writer, loopLinkd->publicationYear, loopLinkd->publisher, loopLinkd->genre);
		loopLinkd = loopLinkd->nextList; //그 후 looplinked가 가리키는 nextlist 포인터의 주소값을 looplinked에 대입 후 while문 반복
	}
	printf("-----------------------------------\n");
}
void menu(struct DataList* dataStart) {

	int sel;
	while (1) {
		printf("=======================\n");
		printf("1.도서 추가 \n");
		printf("2.도서 검색 \n");
		printf("3.도서 정보 수정 \n");
		printf("4.도서 삭제 \n");
		printf("5.현재 총 도서 목록 출력 \n");
		printf("6.저장 \n");
		printf("7.프로그램 나가기(자동저장) \n");
		printf("입력: ");
		scanf("%d", &sel);
		printf("\n");
		switch (sel)
		{
		case 1:
			printf("1.도서 추가 \n");
			dataStart = AddBook(dataStart); //addbook 실행
			break;
		case 2:
			printf("2.도서 검색 \n");
			SearchBook(dataStart); //searchbook 실행
			break;
		case 3:
			printf("3.도서 정보 수정 \n");
			EditBook(dataStart); //editbook 실행
			break;
		case 4:
			printf("4.도서 삭제 \n");
			dataStart = DeleteBook(dataStart); //deletebook 실행
			break;
		case 5:
			printf("5.현재 총 도서 목록 출력 \n"); 
			PrintBook(dataStart); //printbook 실행
			break;
		case 6:
			printf("6.저장 \n"); 
			FileOut(dataStart); //fileout 실행
			break;
		case 7:
			printf("7.프로그램 나가기(자동저장) \n");
			FileOut(dataStart); //fileout 실행
			return;
			break;
		default:
			printf("다시입력하세요.\n");
			break;
		}
		printf("\n");
	}
}

int main() {

	struct DataList* dataStart = NULL; //datastart라는 변수가 datalist 라는 구조체의 주소를 저장하는데 null값을 대입한다.
	dataStart = FileIn(dataStart);     //null값인 datastart를 fileind에 대입후 반환된 datastart값을 datastart에 저장한다.
	menu(dataStart); //메뉴함수에 반환 받은 datastart값을 대입한다.

	return 0;
}