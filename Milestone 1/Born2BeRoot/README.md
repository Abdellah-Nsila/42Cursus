# What is Virtualization ?
Virtualization is a technology that allows you to create a virtual version of a computer system within a single physical machine. This virtual system, called a "virtual machine" (VM), acts like a separate computer with its own operating system, applications, and resources, even though it shares the physical resources (like CPU, memory, and storage) of the host machine.

## What is virtual machine (VMs)?
These are isolated environments on the host system. Each VM has its own OS and runs independently,

## What is Hypervisor ?
A key component in virtualization, a hypervisor is the software layer that enables multiple VMs to run on a single physical host. The hypervisor manages the resources each VM uses, like CPU, memory, and storage. Examples of hypervisors include VirtualBox, VMware, and Hyper-V.

### Why Virtualization?
    Cost-effective: Allows multiple virtual servers to run on a single physical server, saving on hardware costs.
    Flexibility: You can easily create, delete, or modify VMs, which is great for testing and development.
    Isolation: Different environments can run on the same hardware without interfering with each other.
    Scalability: Resources can be dynamically allocated to VMs as needed.

## How does a virtual machine work and what is its purpose?
A virtual machine (VM) works by simulating a complete computer system within software, enabling it to function as an independent computer with its own operating system and applications. The VM relies on a layer of software called a hypervisor to manage and allocate the physical resources of the host machine, such as CPU, memory, and storage, across multiple virtual environments.

## Purpose of Virtual Machines
- Testing and Development
- Running Multiple OSs on One Machine
- Enhanced Security and Isolation
- Efficient Use of Resources
- Education and Training

# Operating System Comparison: Debian vs Rocky Linux

`Basic Differences Between Rocky Linux and Debian`
| Feature                                   | Debian                                                    | Rocky Linux                                                     |
| ----------------------------------------- | --------------------------------------------------------- | ----------------------------------------------------------------|
| Origin                                    | Community-driven, created in 1993.                        | Fork of CentOS, created in 2021.                                |
| Base System                               | Based on Debian GNU/Linux.                                | Derived from Red Hat Enterprise Linux (RHEL).                   |
| Target Users                              | General-purpose, for servers and desktops.                | Primarily enterprise-level servers.                             |
| Package Management                        | Uses apt and .deb packages.                               | Uses dnf/yum and .rpm packages.                                 |
| Stability	Three branches:                 | Stable, Testing, and Unstable. Stable is highly reliable. | Extremely stable, mirroring RHEL releases.                      |
| Security                                  | Utilizes AppArmor for security.                           | Uses SELinux, which is enabled and enforced by default.         |
| Community                                 | Large and highly active.                                  | Growing community after the shift from CentOS to CentOS Stream. |

### Recommendation
- For those new to system administration, Debian is recommended. It offers:
- User-Friendliness: Simplified configurations, allowing beginners to focus on core concepts.
- Robust Community Support: Extensive documentation and community resources.
- Security and Stability: Reliable for server setup without the complex security frameworks of Rocky Linux.

<i>Rocky Linux, while highly stable and suited for enterprise environments, is better suited for users with familiarity in RHEL-based systems and a need for advanced security configurations such as SELinux.<i>




# AppArmor vs SELinux: A Comparison

Here is a detailed comparison table highlighting the differences between **AppArmor** and **SELinux**:

| Feature                        | **AppArmor**                                   | **SELinux**                                                                                                                       |    
|--------------------------------|------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|    
| **Basic Approach**             | Path-based access control.                     | Label-based access control.                                                                                                       |   
| **Configuration**              | Rules are applied to specific file paths.      | Rules are applied to objects with security labels.                                                                                |   
| **Ease of Use**                | Simpler to set up and manage.                  | More complex, with a steeper learning curve.                                                                                      |    
| **Granularity**                | Coarser control; applies to file paths and binaries. | Finer control; applies to every object in the system (files, processes, sockets, etc.).                                     |
| **Policy Writing**             | Easier and more intuitive to write policies.   | Requires understanding of security contexts and labels.                                                                           |
| **Default State**              | Defaults to "complain mode," which logs violations without enforcing rules. | Defaults to "enforcing mode," which actively blocks violations.                                      |
| **Integration**                | Integrated into the Linux kernel with Ubuntu and Debian as primary users. | Integrated into the Linux kernel, heavily used in Red Hat-based systems (e.g., Rocky, Fedora, CentOS). |
| **Performance Impact**         | Minimal impact due to simpler implementation.  | Slightly higher due to label checks on every access.                                                                              |  
| **Flexibility**                | Less flexible compared to SELinux.             | Highly flexible with multi-layered policies.                                                                                      |  
| **Community & Documentation**  | Well-documented for Debian/Ubuntu users.       | Comprehensive documentation for RHEL-based systems.                                                                               |  
| **Security Goals**             | Primarily designed to restrict applications.   | Provides comprehensive system-wide access control.                                                                                |
