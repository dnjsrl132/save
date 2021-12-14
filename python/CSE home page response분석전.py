import requests
import webbrowser
page_num = 2700
page_list_num = 30


while(True):    # find last page_num
    URL = "http://computer.knu.ac.kr/07_sub/01_sub.html?no="+str(page_num)+"&bbs_cmd=view"
    if (requests.get(URL).status_code == 200):
        page_num +=1
    else:
        page_num -=1
        break

for page_num in range(page_num, page_num-page_list_num, -1):
    URL = "http://computer.knu.ac.kr/07_sub/01_sub.html?no="+str(page_num)+"&bbs_cmd=view"
    response = requests.get(URL)
    str1 = response.text
    str2 = str1.split("/pack/bbs/_skin/default/_bbs/_images/mid_bar.gif")
    str3 = str2[1]
    str4 = str3[56:].split("</td>")[0]
    print('[',page_num,']', str4, end='\n\n', sep = '')

def go(page_num):
    URL = "http://computer.knu.ac.kr/07_sub/01_sub.html?no="+str(page_num)+"&bbs_cmd=view"
    webbrowser.open(URL)
