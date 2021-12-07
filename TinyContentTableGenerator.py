from genericpath import isdir
import os , re


# It is quite messy to manage content table manually , so a tiny script is written to handle the issue.

dirs = [directory for directory in os.listdir(os.curdir) if isdir(os.curdir + '\\' + directory)]
file = open('README_test.md' , 'w')
file.write('# LeetCodeRepo\nThis is my personal LeetCodeRepo.\nFeel free to look around.\n\n\n## Contents\n|  \\#   | Title  |\n|  ----  | ----  |\n')
URL_root = 'https://github.com/CheckHarry/LeetCodeRepo/tree/main/'
dirs.remove('.git')
dirs.sort(key = lambda x : int(re.match('^([0-9]*)\. (.*)' , x).group(1) ))
for directory in dirs:
    match = re.match('^([0-9]*)\. (.*)' , directory)
    file.write('|{number}|[{Name}](URL \'{URL}\')|\n'.format(number = match.group(1) , Name = match.group(2) , URL = URL_root + directory.replace(' ' , '%20')))

