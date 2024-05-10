# maldev_101
## :3 my malware developement journey

## Malware attack registry
Registry là nơi lưu các cấu hình của hệ điều hành và các ứng dụng đã cài đặt.
Persistence là cách gọi các phương pháp malware dùng để ẩn mình, nằm sâu trong máy tính nạn nhân.
### Registry Run Keys
Malware có thể tạo và chỉnh sửa Registry key để hệ thống tự động chạy khi khởi động, điều này cho phép malware có thể hoạt động ngay cả sau khi hệ thống khởi động lại.

  Malware bám dai như đỉa (persistence) bằng cách chỉnh sửa các Registry keys của AutoStart Extension Points (ASEPs). Bên dưới là một số Registry mà malware hay dùng ở User level:
      HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunOnce
      HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run

### Startup Folders
Ví dụ, Malware có thể tạo registry key mới để chạy file cụ thể khi hệ thống khởi động.
Một cách khác để bám dai như đỉa (persistence) là dùng thư mục startup. Đây là những folder để lưu những ứng dụng tự động chạy khi người dùng đăng nhập.
Malware có thể tạo một bản sao của nó trong thư mục Startup và nó sẽ được chạy mỗi khi người dùng đăng nhập. 
      HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
      HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
      HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders\
      HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
### Scheduled Tasks
Scheduled Tasks là tính năng cho phép người dùng tự động chạy các chương trình trong một chu trình lặp lại.
Malware có thể dùng tính năng này để khởi tạo persistence trong hệ thống bằng tạo một lịch chạy malware payload.
Registry dùng để lưu trữ Scheduled stasks là 
      HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\TaskCache\Tree key
  
