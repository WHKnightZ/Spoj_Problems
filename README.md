# Spoj Problems

Spoj Problems Solved

## Problems Solved:

- ACODE
- ANARC09A
- COINS
- MKJUMPS
- PQUEUE
- QUE1
- STPAR
- DIEHARD 11:45am 02/05/2020 Đệ quy, Quy hoạch động, Phương pháp ban đầu: sau khi chuyển trạng thái từ Air->Water(Fire), ở đây còn xét cả trường hợp chuyển tiếp sang Fire(Water), thực ra chỉ cần xét chuyển sang Air là đủ do Air cả Health và Armor đều tăng nên sẽ đã viết lại chương trình mới
- CODEM4 03:15pm 02/05/2020 Đệ quy, Minimax, lấy max của 2 trường hợp khi lấy bên trái và bên phải nhưng lần lấy trước cũng ảnh hưởng đến lần lấy sau, cứ như vậy nên ta phải tách đến cái dãy nhỏ nhất để xét trước, nhưng tuy nhiên vẫn phải sử dụng thêm Quy hoạch động để tăng hiệu năng nếu ko sẽ bị TLE
- INVCNT 12:15am 03/05/2020 Merge sort, lúc đầu sử dụng thuật toán tương tự Selection sort -> o(n2) chậm -> chuyển thành o(nlogn)
- ARRANGE 04:30pm 03/05/2020 bài này khá "hài", chỉ sử dụng mỗi toán học
- EZSUDOKU 07:45am 05/05/2020 kết hợp Quay lui + Quy hoạch động (lưu trữ)
- ALLIZWEL 10:15am 05/05/2020 DFS với những điểm là 'A', xét 8 hướng, nếu theo hướng đó đi được thì DFS tiếp
- SPIKES 05:00pm 05/05/2020 DFS từ những đỉnh là '@', cần 2 mảng để đánh dấu trạng thái trước và sau khi gặp dấu 'x', tuy nhiên có thể BFS sẽ tốt hơn. Ngoài ra có thể thấy khi chọn đường tốt nhất để đến x (số lần gặp spike ít nhất) thì đường quay lại cũng vậy nên ta chỉ cần xét xem có đường nào đi đến x mà số lần gặp Spike nhỏ hơn hoặc bằng 1/2 số mạng là ổn, ko cần quay lại nữa
- BYTESM2 09:50am 07/05/2020 Khá quen thuộc, cơ bản là với mỗi vị trí cần xét 3 vị trí bên dưới, chọn cái lớn nhất trong 3 cái này, áp dụng thêm quy hoạch động để ko phải tính toán nhiều lần
- PT07Y 11:35am 07/05/2020 Để là cây thì phải có số đỉnh = số cạnh + 1 đồng thời liên thông => DFS để kiểm tra liên thông
- SHOP 02:00pm 07/05/2020 Dijkstra quá quen rồi
- CSTREET 04:25pm 07/05/2020 Sử dụng prim nhưng cũng chẳng biết đúng không
- EKO 06:45pm 07/05/2020 Đán án sẽ nằm trong đoạn (max, max-1, ... 0) với max là chiều cao cây cao nhất, Thay vì việc tìm kiếm lần lượt từ max trở về thì ta có thể sử dụng tìm kiếm nhị phân, chia làm 2 đoạn bằng nhau, xem đoạn bên nào thỏa mãn
- MICEMAZE 02:00pm 08/05/2020 Lại là Dijkstra, nhưng tuy nhiên là tìm đường từ End ngược về các đỉnh, lưu ý cần check đường đi từ điểm con ở sau đến điểm đang xét
- BUGLIFE 07:00pm 09/05/2020 Cơ bản là dùng BFS check xem có tồn tại chu trình trong đồ thị không, nhưng lưu ý là hai điểm tạo chu trình phải khác giới tính, mình cơ bản là dùng mảng Queue[] để lưu giới tính của những con ruồi đã được thêm vào hàng đợi, chưa thêm thì có giá trị 0, thêm rồi thì có giá trị 1 hoặc 2 (giới tính ngược lại với điểm cha)
- CLEANRBT 11:00am 10/05/2020 Đầu tiên dùng BFS để tìm đường đi ngắn nhất giữa các đỉnh đồ thị, sau đó bài toán cần xét là tìm đường đi ngắn nhất qua tất cả các đỉnh từ một đỉnh xuất phát, sử dụng DFS
- RMID2 08:50pm 10/05/2020 Sử dụng 2 hàng đợi ưu tiên, dãy bên trái giảm dần, bên phải tăng dần, số phần tử ở bên dãy trái luôn bằng bên phải hoặc hơn phải 1, như vậy thì phần tử đầu dãy trái chính là trung vị. Khi sử dụng scanf, printf thay cho cin, cout hiệu năng tăng đáng kể