import subprocess
import re

def get_star_commits():
    """ 获取所有以 'star' 开头的 commit 及其 message """
    result = subprocess.run(
        ['git', 'log', '--grep=^star', '--format=%s'],
        capture_output=True, text=True, encoding='utf-8'
    )
    return result.stdout.strip().split('\n')

def get_commit_files(commit_message):
    """ 获取指定 commit message 关联的 .cpp 文件 """
    result = subprocess.run(
        ['git', 'log', '--grep', f'^{commit_message}$', '--format=%H', '-n', '1'],
        capture_output=True, text=True, encoding='utf-8'
    )
    commit_hash = result.stdout.strip()

    if not commit_hash:
        return []

    result = subprocess.run(
        ['git', 'diff-tree', '--no-commit-id', '--name-only', '-r', commit_hash],
        capture_output=True, text=True, encoding='utf-8'
    )
    files = result.stdout.strip().split('\n')
    return commit_hash, [file for file in files if file.endswith('.cpp')]

def get_first_line_from_file(commit_hash, file):
    """ 获取文件的第一行内容 """
    result = subprocess.run(
        ['git', 'show', f'{commit_hash}:{file}'],
        capture_output=True, text=True, encoding='utf-8', errors='ignore'
    )
    first_line = result.stdout.strip().split('\n')[0] if result.stdout else ""
    return first_line

def extract_problem_info(first_line):
    """ 提取题号和难度分 """
    match = re.match(r'//\s*(\S+)\s+(\S+)', first_line)
    if match:
        return match.group(1), match.group(2)
    return None, None

def main():
    star_commits = get_star_commits()

    for commit_message in star_commits:
        if not commit_message:
            continue

        commit_hash, cpp_files = get_commit_files(commit_message)
        for file in cpp_files:
            first_line = get_first_line_from_file(commit_hash, file)
            problem_id, difficulty = extract_problem_info(first_line)

            if problem_id and difficulty:
                # commit, date, problem_id, difficulty
                # file = (str)"250512.cpp" -> date = "25/05/12"
                year = "20" + file[0:2]
                month = file[2:4]
                day = file[4:6]
                date = f"{year}/{month}/{day}"
                print(f"{commit_message[5:]}, {date}, {problem_id}, {difficulty}")

if __name__ == "__main__":
    main()
