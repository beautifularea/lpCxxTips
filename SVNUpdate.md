执行svn update，弹出一堆乱码，最后显示要Cleanup command.</br>
解决办法：</br>
1 下载sqlite3.ext</br>
2 找到被锁定目录下的隐藏文件.svn</br>
3 在终端中定位到本目录，执行命令：sqlite3.ext .svn/wc.db "select * from work_queue"</br>
4 再执行命令 sqlite3.ext .svn/wc.db "select from work_queue"</br>
</br>
然后svn update, 此时要么成功，要么没有乱码了但是依然提示要cleanup.</br>
接着cleanup ,选中 【break locks】</br>
成功！</br>



FYI: </br>
***不用SVN好多年了，结果新公司用的还是SVN，感觉一下又回到了解放前，还得把SVN的坑再踩一遍！***

