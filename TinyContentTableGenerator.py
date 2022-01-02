from genericpath import isdir
import os , re
from sys import platform
from pprint import pprint

# It is quite messy to manage content table manually , so a tiny script is written to handle the issue.
if platform == "linux" or platform == "linux2":
    dirs = [directory for directory in os.listdir(os.curdir) if isdir(os.curdir + '/' + directory)]
else:
    dirs = [directory for directory in os.listdir(os.curdir) if isdir(os.curdir + '\\' + directory)]

file = open('README.md' , 'w')
file.write('# LeetCodeRepo\nThis is my personal LeetCodeRepo.\nFeel free to look around.\n\n\n## Contents\n|  \\#   | Title  |\n|  ----  | ----  |\n')
URL_root = 'https://github.com/CheckHarry/LeetCodeRepo/tree/main/'
try: 
    dirs.remove('.git')
except:
    pass

dirs.sort(key = lambda x : int(re.match('^([0-9]*)\. (.*)' , x).group(1) ))
pprint(dirs)
for directory in dirs:
    match = re.match('^([0-9]*)\. (.*)' , directory)
    file.write('|{number}|[{Name}]({URL})|\n'.format(number = match.group(1) , Name = match.group(2) , URL = URL_root + directory.replace(' ' , '%20')))

