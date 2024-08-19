import os

tasks = [
    ("A - Frog 1", "https://atcoder.jp/contests/dp/tasks/dp_a"),
    ("B - Frog 2", "https://atcoder.jp/contests/dp/tasks/dp_b"),
    ("C - Vacation", "https://atcoder.jp/contests/dp/tasks/dp_c"),
    ("D - Knapsack 1", "https://atcoder.jp/contests/dp/tasks/dp_d"),
    ("E - Knapsack 2", "https://atcoder.jp/contests/dp/tasks/dp_e"),
    ("F - LCS", "https://atcoder.jp/contests/dp/tasks/dp_f"),
    ("G - Longest Path", "https://atcoder.jp/contests/dp/tasks/dp_g"),
    ("H - Grid 1", "https://atcoder.jp/contests/dp/tasks/dp_h"),
    ("I - Coins", "https://atcoder.jp/contests/dp/tasks/dp_i"),
    ("J - Sushi", "https://atcoder.jp/contests/dp/tasks/dp_j"),
    ("K - Stones", "https://atcoder.jp/contests/dp/tasks/dp_k"),
    ("L - Deque", "https://atcoder.jp/contests/dp/tasks/dp_l"),
    ("M - Candies", "https://atcoder.jp/contests/dp/tasks/dp_m"),
    ("N - Slimes", "https://atcoder.jp/contests/dp/tasks/dp_n"),
    ("O - Matching", "https://atcoder.jp/contests/dp/tasks/dp_o"),
    ("P - Independent Set", "https://atcoder.jp/contests/dp/tasks/dp_p"),
    ("Q - Flowers", "https://atcoder.jp/contests/dp/tasks/dp_q"),
    ("R - Walk", "https://atcoder.jp/contests/dp/tasks/dp_r"),
    ("S - Digit Sum", "https://atcoder.jp/contests/dp/tasks/dp_s"),
    ("T - Permutation", "https://atcoder.jp/contests/dp/tasks/dp_t"),
    ("U - Grouping", "https://atcoder.jp/contests/dp/tasks/dp_u"),
    ("V - Subtree", "https://atcoder.jp/contests/dp/tasks/dp_v"),
    ("W - Intervals", "https://atcoder.jp/contests/dp/tasks/dp_w"),
    ("X - Tower", "https://atcoder.jp/contests/dp/tasks/dp_x"),
    ("Y - Grid 2", "https://atcoder.jp/contests/dp/tasks/dp_y"),
    ("Z - Frog 3", "https://atcoder.jp/contests/dp/tasks/dp_z")
]

cpp_template = """\
/*
Problem Name: {task_name}
Problem Link: {task_link}
Idea: 
Complexity:
Resource:
*/

"""

for task_name, task_link in tasks:
    file_name = f"{task_name}.cpp"
    if not os.path.exists(file_name):
        with open(file_name, "w") as file:
            file.write(cpp_template.format(task_name=task_name, task_link=task_link))
        print(f"Created '{file_name}'")
    else:
        print(f"'{file_name}' already exists, skipping creation.")

print("C++ file creation process completed.")
