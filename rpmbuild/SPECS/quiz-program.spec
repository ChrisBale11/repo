Name:           quiz-game
Version:        0.1
Release:        1%{?dist}
Summary:        quiz-game example implemented in python
License:        GPLv3+
Source0:        %{name}-%{version}.tar.gz
BuildRequires:  python3
Requires:       python3 bash
BuildArch:      noarch


%description
The long-tail description for our Quiz Game Example implemented in
Python.
%prep
%setup -q

%build

python3  -m compileall %{name}.py


%install
mkdir -p %{buildroot}%{_bindir}
mkdir -p %{buildroot}/usr/lib/%{name}

cat > %{buildroot}%{_bindir}/%{name} <<-EOF
#!/bin/bash
/usr/bin/python /usr/lib/%{name}/%{name}.pyc
EOF

chmod 0755 %{buildroot}%{_bindir}/%{name}
install -m 0644 %{name}.py* %{buildroot}/usr/lib/%{name}/

%files
%license LICENSE
%dir /usr/lib/%{name}/
%{_bindir}/%{name}
/usr/lib/%{name}/%{name}.py*

%changelog
  - First quiz game package