import os

tasks = [
    ("Frog 1", "https://atcoder.jp/contests/dp/tasks/dp_a"),
    ("Frog 2", "https://atcoder.jp/contests/dp/tasks/dp_b"),
    ("Vacation", "https://atcoder.jp/contests/dp/tasks/dp_c"),
    ("Knapsack 1", "https://atcoder.jp/contests/dp/tasks/dp_d"),
    ("Knapsack 2", "https://atcoder.jp/contests/dp/tasks/dp_e"),
    ("LCS", "https://atcoder.jp/contests/dp/tasks/dp_f"),
    ("Longest Path", "https://atcoder.jp/contests/dp/tasks/dp_g"),
    ("Grid 1", "https://atcoder.jp/contests/dp/tasks/dp_h"),
    ("Coins", "https://atcoder.jp/contests/dp/tasks/dp_i"),
    ("Sushi", "https://atcoder.jp/contests/dp/tasks/dp_j"),
    ("Stones", "https://atcoder.jp/contests/dp/tasks/dp_k"),
    ("Deque", "https://atcoder.jp/contests/dp/tasks/dp_l"),
    ("Candies", "https://atcoder.jp/contests/dp/tasks/dp_m"),
    ("Slimes", "https://atcoder.jp/contests/dp/tasks/dp_n"),
    ("Matching", "https://atcoder.jp/contests/dp/tasks/dp_o"),
    ("Independent Set", "https://atcoder.jp/contests/dp/tasks/dp_p"),
    ("Flowers", "https://atcoder.jp/contests/dp/tasks/dp_q"),
    ("Walk", "https://atcoder.jp/contests/dp/tasks/dp_r"),
    ("Digit Sum", "https://atcoder.jp/contests/dp/tasks/dp_s"),
    ("Permutation", "https://atcoder.jp/contests/dp/tasks/dp_t"),
    ("Grouping", "https://atcoder.jp/contests/dp/tasks/dp_u"),
    ("Subtree", "https://atcoder.jp/contests/dp/tasks/dp_v"),
    ("Intervals", "https://atcoder.jp/contests/dp/tasks/dp_w"),
    ("Tower", "https://atcoder.jp/contests/dp/tasks/dp_x"),
    ("Grid 2", "https://atcoder.jp/contests/dp/tasks/dp_y"),
    ("Frog 3", "https://atcoder.jp/contests/dp/tasks/dp_z")
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

# Generate .cpp files for each task
for task_name, task_link in tasks:
    file_name = f"{task_name}.cpp"
    with open(file_name, "w") as file:
        file.write(cpp_template.format(task_name=task_name, task_link=task_link))

print("C++ files created successfully.")
