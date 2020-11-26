"""
refresh README.md
"""
import argparse
import os.path as osp

def get_args():
    parser = argparse.ArgumentParser()

    parser.add_argument(
        '--refresh', '-r',
        action='store_true',
        help='refreah README.md'
    )

    args = parser.parse_known_args()[0]
    return args

def refreah():
    dirname = osp.dirname(__file__)
    filepath = osp.join(dirname, "README.md")

    with open(filepath, 'r+', encoding='utf-8') as f:
        content = f.read()
        row_list = content.split('\n')
        # found the un-packed row
        un_packed_rows = []
        dict_cata = {}
        dict_row_flag = False
        date_row_flag = False
        dict_row_num  = 0
        date_row_num  = 0
        cur_cata = None
        for idx, row in enumerate(row_list):
            if dict_row_flag:
                if "### " in row[:4]:
                    cur_cata = row[4:]
                    dict_cata.setdefault(cur_cata, [])
                elif "- " in row[:2]:
                    dict_cata[cur_cata] = [row] + dict_cata[cur_cata]
            else:
                if row == "## 归档":
                    dict_row_flag = True
                    dict_row_num  = idx + 1
            if date_row_flag:
                if '- uu ' in row[:5]:
                    un_packed_rows = [row] + un_packed_rows
                    row_list[idx] = "- " + row[5:]
            else:
                if row == "## 日期归档":
                    date_row_flag = True
                    dict_row_flag = False
                    date_row_num  = idx + 1
        # pack those rows to "## 日期归档"
        for row in un_packed_rows:
            row = row.split(' ')
            catas = row[4:-1]
            for c in catas:
                dict_cata.setdefault(c, [])
                row_ = '- ' + row[3] + ' ' + row[-1] + ' ' + row[2]
                dict_cata[c].append(row_)
        # del file "## 归档"
        row_list_a = row_list[:dict_row_num]
        row_list_c = row_list[date_row_num-2:]
        ## row_list_b
        row_list_b = []
        for key in dict_cata:
            row_list_b.append("\n### " + key)
            for row in dict_cata[key]:
                row_list_b.append(row)
        row_list_b[0] = row_list_b[0][1:]
        row_list = row_list_a + row_list_b + row_list_c
    
    with open(filepath, 'w', encoding='utf-8') as f:
        for row in row_list:
            f.write(row + '\n')
    
    print("\033[1;34mREADME.md 完成刷新\033[0m")
    print("\033[1;36mhttps://github.com/PiperLiu/ACMOI_Journey\033[0m")
    print("star", end="")
    print("\033[1;36m the above repo \033[0m", end="")
    print("and practise together!")

def main(args=get_args()):
    if args.refresh:
        refreah()

if __name__ == "__main__":
    main()
