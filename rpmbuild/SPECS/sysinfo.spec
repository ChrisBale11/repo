Name:       sysinfo
Version:    0.1
Release:    1%{?dist}
Summary:    Get system information example implemented in C
License:    GPLv3+
Source0:    %{name}-%{version}.tar.gz

BuildRequires: gcc
BuildRequires: make

%description
The long-tail description for our getting system information  Example implemented in
C.
%prep
%setup -q

%build
make %{?_smp_mflags}
%install
%make_install
%files
%license LICENSE
%{_bindir}/%{name}
%changelog
- First cello package
