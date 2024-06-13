Name:       hello
Version:    1
Release:    1
Summary:    Most simple RPM package
License:    FIXME
BuildArch:  noarch


%description
This is my first RPM package, which does nothing.

%prep
# we have no source, so nothing here

%build
cat > hello.sh <<EOF
#!/usr/bin/bash
echo "Hello \$1"
EOF

%install
mkdir -p %{buildroot}/usr/bin/
install -m 755 hello.sh %{buildroot}/usr/bin/hello

%files
/usr/bin/hello

%changelog
# let's skip this for now



