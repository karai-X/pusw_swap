# プロジェクト概要
ある制約条件のもと、少ない操作手順でソートするプログラム。
# 制約条件
1. AとBの2つのスタックが与えられる。  
2. 行うことのできる操作は以下のみ  
   ✅ スワップ（swap）  
   sa: stack A の上の2つの要素を交換  
   sb: stack B の上の2つの要素を交換  
   ss: sa と sb を同時に実行  
   ✅ プッシュ（push）  
   pa: B の一番上を A に移動  
   pb: A の一番上を B に移動  
   ✅ ローテート（rotate）  
   ra: A を上に1つ回す（先頭が最後へ）    
   rb: B を上に1つ回す  
   rr: ra と rb を同時に実行  
   ✅ 逆ローテート（reverse rotate）  
   rra: A を下に1つ回す（最後尾が先頭へ）  
   rrb: B を下に1つ回す  
   rrr: rra と rrb を同時に実行  
# 実行方法
```
git clone https://github.com/karai-X/pusw_swap.git
```
```
make
```
```
./push_swap 5 4 1 3 9
```
## 入力
./push_swap (正の整数)  
## 出力
並び替えるための操作が出力される。
## 実行例
```
./push_swap 5 4 1 3 9
```
出力
```
pb  
ra  
ra  
ra  
pb  
ra  
sb  
pa  
ra  
pa  
ra  
```
# Visualizer
https://github.com/user-attachments/assets/86ae43b5-371b-46be-95aa-6ab595fa1bdb


