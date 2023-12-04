#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Contact {
    int id, status;
    char name[50], phone[12], address[50];
};

void printfMenu() {
    printf("**********MENU***********\n");
    printf("1.In toan bo danh sach contact o trong mang contactList tren cung 1 hang\n");
    printf("2.Thuc hien chuc nang them moi vao vi tri cuoi cung cua contactList\n");
    printf("3.Chinh sua thong tin trong contactList\n");
    printf("4.Xoa thong tin trong contactList\n");
    printf("5.Sap xep va in ra danh sach contact da duoc sap xep\n");
    printf("6.Tim kiem nhi phan va in ra thong tin cua contact tren cung mot hang\n");
    printf("7.Tim kiem tuyen tinh va in ra thong tin cua contact\n");
    printf("8.Thoat\n");
    printf("Lua chon cua ban la: ");
}

void printContact(struct Contact arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d\t", arr[i].id);
        printf("Ho va Ten: %s\t", arr[i].name);
        printf("So Dien Thoai: %s\t", arr[i].phone);
        printf("Dia chi: %s\t", arr[i].address);
        printf("Trang Thai: %d\n", arr[i].status);
        printf("-----------------------\n");
    }
}

int main() {
	char searchName[50];
	int foundIndex;
	int searchStatus,found;
	int left,right,middle;
    struct Contact ct1 = {1, 1, "Nguyen The Minh", "095852985", "Ha Noi"};
    struct Contact ct2 = {2, 2, "Nguyen Nam Son", "047358472", "Ha Noi"};
    struct Contact ct3 = {3, 1, "Le Dien Tien", "047847525", "Thai Nguyen"};
    struct Contact ct4 = {4, 2, "Nguyen Minh Hien", "0486745156", "Soc Son"};
    struct Contact ct5 = {5, 1, "Luong Minh Vy", "0785676558", "Thanh Hoa"};
    struct Contact contactList[] = {ct1, ct2, ct3, ct4, ct5};
    int contactCount = 5;

    do {
        printfMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printContact(contactList, contactCount);
                break;
            case 2:           	
                break;
            case 3:		        
                break;
            case 4:
                break;
            case 5:
				//Noi Bot
			    for (int i = 0; i < contactCount - 1; i++) {
			        for (int j = 0; j < contactCount - i - 1; j++) {
			            if (strcmp(contactList[j].name, contactList[j + 1].name) > 0) {
			                struct Contact temp = contactList[j];
			                contactList[j] = contactList[j + 1];
			                contactList[j + 1] = temp;
			            }
			        }
			    }
			    printf("Danh sach contact da duoc sap xep:\n");
			    printContact(contactList, contactCount);
                break;
            case 6:
            	for (int i = 0; i < contactCount - 1; i++) {
			        for (int j = 0; j < contactCount - i - 1; j++) {
			            if (strcmp(contactList[j].name, contactList[j + 1].name) > 0) {
			                struct Contact temp = contactList[j];
			                contactList[j] = contactList[j + 1];
			                contactList[j + 1] = temp;
			            }
			        }
			    }
			    printf("Nhap ten contact muon tim kiem: ");
			    scanf("%s", searchName);
			    left = 0;
			    right = contactCount - 1;
			    found = 0;
			    while (left <= right) {
			        middle = (left + right) / 2;
			        if (strcmp(contactList[middle].name, searchName) == 0) {
			            found = 1;
			            foundIndex = middle;
			            break;
			        } else if (strcmp(contactList[middle].name, searchName) < 0) {
			            left = middle + 1;
			        } else {
			            right = middle - 1;
			        }
			    }
			    if (found) {
			        printf("ID: %d\t", contactList[foundIndex].id);
			        printf("Ten: %s\t", contactList[foundIndex].name);
			        printf("So Dien Thoai: %s\t", contactList[foundIndex].phone);
			        printf("Dia chi: %s\t", contactList[foundIndex].address);
			        printf("Trang Thai: %d\n", contactList[foundIndex].status);
			        printf("-----------------------\n");
			    } else {
			        printf("Khong tim thay contact.\n");
		    	}
                break;
            case 7:
			    printf("Nhap trang thai contact muon tim kiem: ");
			    scanf("%d", &searchStatus);
			    found = 0;
			    for (int i = 0; i < contactCount; i++) {
			        if (contactList[i].status == searchStatus) {
			            printf("ID: %d\t", contactList[i].id);
			            printf("Ten: %s\t", contactList[i].name);
			            printf("So Dien Thoai: %s\t", contactList[i].phone);
			            printf("Dia chi: %s\t", contactList[i].address);
			            printf("Trang Thai: %d\n", contactList[i].status);
			            printf("-----------------------\n");
			            found = 1;
			        }
			    }
			    if (!found) {
			        printf("Khong tim thay contact voi trang thai tuong ung.\n");
    			}
                break;
            case 8:
                printf("Ket thuc chuong trinh");
                exit(0);
            default:
                printf("Khong hop le");
        }
    } while (1==1);
}
