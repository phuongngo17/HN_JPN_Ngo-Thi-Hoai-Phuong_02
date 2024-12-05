#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
void dem_chan_le(int arr[], int n) {
    int chan = 0, le = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            chan++;
        } else {
            le++;
        }
    }
    printf("So phan tu chan: %d\n", chan);
    printf("So phan tu le: %d\n", le);
}

bool binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return true;
        if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void in_so_nguyen_to_binh_phuong(int arr[], int n) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            found = true;
            printf("%d^2 = %d\n", arr[i], arr[i] * arr[i]);
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nao trong mang.\n");
    }
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
	int arr[100];
	int choice,n;
	int value,found;
	while(1){
		printf("\nMenu\n");
		printf("1.Nhap so phan tu va gia tri cho mang\n");
		printf("2.In ra gia tri cac phan tu trong mang theo dong (arr[0] = 1, arr[1] = 5...)\n");
		printf("3.Dem so luong cac phan tu chan le trong mang\n");
		printf("4.Tim gia tri lon thu hai trong mang\n");
		printf("5.Them mot phan tu vao dau mang, phan tu moi them vao mang phai do nguoi dung nhap vao\n");
		printf("6.Xoa phan tu tai mot vi tri cu the (nguoi dung nhap vi tri)\n");
		printf("7.Sap xep mang theo thu tu giam dan (Insertion sort)\n");
		printf("8.Cho nguoi dung nhap vao mot phan tu, tim kiem xem phan tu do co ton tai trong mang hay khong (Binary search)\n");
		printf("9.In ra toan bo so nguyen tu trong mang da duoc binh phuong\n");
		printf("10.Sap xep mang theo thu tu giam dan (Bubble sort)\n");
		printf("11.Thoat chuong trinh\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("nhap so phan tu ");
				scanf("%d",&n);
				printf("nhap gia tri phan tu\n");
				for(int i = 0;i < n;i++){
						printf("nhap arr [%d]: ",i);
						scanf("%d",&arr[i]);
				}
				break;
			case 2:
				for (int i = 0; i < n; i++) {
                    printf(" gia tri cac phan tu mang la arr[%d]= %d \n ",i,arr[i]);
                }
				break;
			case 3:
				dem_chan_le(arr,n);
				break;
			case 4:
				if (n < 2) {
                    printf("Khong co gia tri lon thu hai.\n");
                    return;
                }
                int max1 = arr[0], max2 = -1;
				for (int i = 1; i < n; i++) {
				    if (arr[i] > max1) {
				        max2 = max1;
				        max1 = arr[i];
				    } else if (arr[i] > max2 && arr[i] != max1) {
				        max2 = arr[i];
				    }
				}
				if (max2 == -1) {
				    printf("Khong co gia tri lon thu hai.\n");
				} else {
				    printf("Gia tri lon thu hai trong mang la: %d\n", max2);
				}
				break;
			case 5:
			 if (n < 100) {
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &value);
                    arr[n++] = value;
                    printf("Phan tu da duoc them.\n");
                } else {
                    printf("Mang da day!\n");
                }
				break;
			case 6:
				printf("Nhap gia tri phan tu can xoa: ");
                scanf("%d", &value);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        found = 1;
                        for (int j = i; j < n - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        n--;
                        break;
                    }
                }
                if (found) {
                    printf("Phan tu da duoc xoa.\n");
                } else {
                    printf("Khong tim thay phan tu trong mang!\n");
                }
				break;
			case 7:
				for (int i = 1; i < n; i++) {
			        int key = arr[i];
			        int j = i - 1;
			        while (j >= 0 && arr[j] < key) {
			            arr[j + 1] = arr[j];
			            j--;
			        }
			        arr[j + 1] = key;
			    }
                printf("Mang da duoc sap xep giam dan.\n");
				break;
			case 8:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (binarySearch(arr, n, value)) {
                    printf("Phan tu %d co ton tai trong mang\n", value);
                } else {
                    printf("Phan tu %d khong ton tai trong mang\n", value);
                }
                break;
			case 9:
				in_so_nguyen_to_binh_phuong(arr, n);
				break;
			case 10:
				bubble_sort(arr, n);
				break;
			case 0:
				exit(0);
			default:
	                printf("Lua chon khong hop le\n");
		}
	}
	return 0;
}
