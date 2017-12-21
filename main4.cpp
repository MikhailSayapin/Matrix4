#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{

    if (argc == 1)
    {
        cout << " Матрица пустая. " << endl;
        return 0;
    }

    string str1 = "\0", str2 = "\0";
    int x, y, i, j, k, m, n;
    for (k = 0; argv[1][k] != '*'; k++)
    {
        str1 += argv[1][k];
    }

    k++;

    while (k != strlen(argv[1]))
    {
        str2 += argv[1][k];
        k++;
    }

    k = 2;

    x = atoi(str1.c_str());
    y = atoi(str2.c_str());

    int arr[x][y];

    if ((argc - 2) > (x * y))
    {
        cout << " \nПереполнение элементами матрицы размера " << x << "*" << y << endl;
        return 0;
    }

    if ((argc - 2) < (x * y))
    {
        cout << " \nНедостаточно элементов для матрицы размера " << x << "*" << y << endl;
        return 0;
    }


    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            arr[i][j] = atoi(argv[k]);
            k++;
        }
    }


    while (true)
    {
    label_case:
        cout << "\nВыберите одну из операций:" << endl;
        cout << "1. Вывести матрицу" << endl;
        cout << "2. Сложить матрицу" << endl;
        cout << "3. Умножить матрицу" << endl;
        cout << "4. Транспонировать матрицу" << endl;
        cout << "5. Сохранить в файл" << endl;
        cout << "6. Загрузить из файла" << endl;
        cout << "7. Сортировать матрицу" << endl;
        cout << "8. Выйти\n" << endl;
        cin >> k;
        switch (k)
        {
            case 8:
            {
                cout << "До свидания!" << endl;
                return 0;
            }


            case 1:
            {
                cout << endl;
                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }


            case 2:
            {
                cout << endl;
                cout << "Введите элементы матрицы размера " << x << "*" << y << endl;
                int arroper[x][y];
                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                        cin >> arroper[i][j];
                    }
                }

                cout << endl;

                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                        cout << arr[i][j] + arroper[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }


            case 3:
            {
                cout << endl;
                cout << "Введите кол-во строк" << endl;
                cin >> m;
                cout << "Введите кол-во столбцов" << endl;
                cin >> n;

                if (m != y)
                {
                    cout << "Число строк в исходной матрице не равно числу столбцов в данной.\n";
                    goto label_case;
                }

                cout << "Введите элементы матрицы размера " << m << "*" << n << endl;

                int arroper[m][n];
                for (j = 0; j < m; j++)
                {
                    for (int q = 0; q < n; q++)
                    {
                        cin >> arroper[j][q];
                    }
                }

                int arroper2[x][n];
                for (i = 0; i < x; i++)
                {
                    for (int q = 0; q < n; q++)
                    {
                        arroper2[i][q] = 0;
                    }
                }

                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                        for (int q = 0; q < n; q++)
                        {
                            arroper2[i][q] = arr[i][j] * arroper[j][q] + arroper2[i][q];
                        }
                    }
                }

                for (i = 0; i < x; i++)
                {
                    for (int q = 0; q < n; q++)
                    {
                        cout << arroper2[i][q] << " ";
                    }
                    cout << endl;
                }


                break;
            }


            case 4:
            {
                cout << endl;
                for (i = 0; i < y; i++)
                {
                    for (j = 0; j < x; j++)
                    {
                        swap(i, j);
                        cout << arr[i][j] << " ";
                        swap(j, i);
                    }
                    cout << endl;
                }
            }

            break;


            case 5:
            {
                char f[100];
                cout << "Укажите название файла\t";
                cin >> f;
                ofstream fout;
                fout.open(f);

                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                        fout << arr[i][j] << " ";
                    }
                    fout << endl;
                }

                fout.close();
                break;
            }


            case 6:
            {
                char f[100];
                string* name = new string;
                cout << "Укажите путь к файлу\t";
                cin >> f;
                ifstream file(f, ios::in);
                if (!file.is_open())
                {
                    cout << "\nОшибка открытия файла!\n";
                    goto label_case;
                }
                while (!file.eof())
                {
                    getline(file, *name);
                    cout << *name << endl;
                }

                break;
            }


            case 7:
            {
                char z;
                cout << "\nВыберите порядок сортировки\n";
                cin >> z;

                if (z == 's')
                {
                    i = 1;
                    while (i < x)
                    {
                        for (j = 0; j < y / 2; j++)
                        {
                            swap(arr[i][j], arr[i][y - j - 1]);
                            i += 2;
                        }
                    }

                    for (i = 0; i < y; i++)
                    {
                        for (j = 0; j < x; j++)
                        {
                            swap(i, j);
                            cout << arr[i][j] << " ";
                            swap(j, i);
                        }
                        cout << endl;
                    }
                }
            }


            default:
                cout << "\nНомер операции введён неверно.\n";
        }
    }

    return 0;
}
