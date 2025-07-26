# STM32 学习项目（基于江科大框架）

本项目是一个基于 STM32 的嵌入式学习项目，结构参考江科大视频教程，旨在通过模块化的方式逐步掌握 STM32 基础外设开发，包括 GPIO、外部中断、定时器、PWM 等。

---

## 📁 项目结构

├── Hardware/ # 与硬件相关的驱动代码（GPIO、LED、按键、串口等）
├── Library/ # STM32 标准外设库（CMSIS、启动文件等）
├── Listings/ # 汇编或反汇编文件输出目录（编译生成，可忽略）
├── Object/ # 编译生成的中间目标文件（可忽略）
├── Start/ # 启动文件与系统初始化
├── System/ # 系统功能模块（如定时器封装、延时、时钟等）
├── User/ # 用户主函数 main.c 所在目录
├── README.md # 项目说明文档
└── .gitignore # Git 忽略规则



---

## ✅ 已实现功能

- [x] LED 灯闪烁（GPIO 输出）
- [x] 按键检测（GPIO 输入 + 外部中断）
- [x] 定时器中断（SysTick / TIMx）
- [x] PWM 波形输出（TIMx PWM）
- [ ] 串口通信（USART）
- [ ] ADC 模数转换
- [ ] I2C/SPI 设备驱动



---

## 🧰 开发环境

- IDE：Keil uVision5 / STM32CubeIDE
- 编译器：ARMCC / GCC
- 硬件平台：STM32F103C8T6（或其他 STM32 芯片）



---

## 🚀 快速开始

1. 克隆本仓库到本地：

   ```bash
   git clone https://github.com/yourname/stm32-learning.git
使用 Keil 或 CubeIDE 打开项目。

编译并烧录到开发板。

根据模块在 User/main.c 中调用功能函数。



📌 命名规范与模块说明
文件夹	功能描述
Hardware/	存放外设底层驱动，结构清晰独立
System/	封装系统相关功能，如延时、时钟等
Start/	启动代码与中断向量表
User/	用户主函数、测试逻辑入口
Library/	ST 官方库文件，保持原样



📝 TODO
 优化文件结构，支持 CubeMX 自动生成结构

 抽象外设驱动为统一 API 接口

 增加 HAL 版本示例以适配 CubeIDE

 添加 FreeRTOS 最小系统演示



📖 参考资源
江科大 STM32 教学视频（哔哩哔哩）

《STM32F103 入门与实践》

ST 官方文档与参考手册



📄 License
本项目仅用于学习交流，版权归原作者所有，禁止用于商业用途。