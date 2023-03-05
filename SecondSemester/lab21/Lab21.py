import argparse
import os


def get_args():
    parser = argparse.ArgumentParser(description='Properties of deleted files')
    parser.add_argument('-p', '--prefix', type=str, help='Input prefix of files')
    parser.add_argument('-s', '--size', type=int, help='Total size of remaining files (in bytes)')
    args = parser.parse_args()

    return (args.prefix, args.size)


def remove_files(prefix, size):
    files_list = []

    for root, dirs, files in os.walk('/'):
        for file in files:
            if file.startswith(prefix):
                files_list.append(os.path.join(root, file))

            elif file.startswith(prefix) is None:
                continue

    files_list.sort(key=lambda f: os.path.getsize(os.path.join(root, f)))
    files_size = sum(os.path.getsize(os.path.join(root, file)) for file in files_list)

    count_delete_files = 0

    while size < files_size:
        file_delete = files_list.pop(-1)
        files_size -= os.path.getsize(os.path.join(root, file_delete))
        os.remove(os.path.join(root, file_delete))
        count_delete_files += 1
        print(f'Deleted file: {file_delete}')

    print(f'\nNumber of deleted files: {count_delete_files}')


def main():
    prefix, size = get_args()
    remove_files(prefix, size)


if __name__ == '__main__':
    main()
