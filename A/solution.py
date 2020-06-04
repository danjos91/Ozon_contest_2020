def main():

    file = open('input-201.txt', "r")
    numbers_str = file.read().split()
    file.close()
    for i in numbers_str:
        value = numbers_str.count(i)
        if value == 1:
            file1 = open('input-201.a.txt', "a")
            file1.write(i)
            file1.close()
            return

if __name__ == '__main__':
    main()
