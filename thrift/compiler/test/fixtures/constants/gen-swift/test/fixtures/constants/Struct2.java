/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.constants;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftStruct(value="struct2", builder=Struct2.Builder.class)
public final class Struct2 {
    @ThriftConstructor
    public Struct2(
        @ThriftField(value=1, name="a", requiredness=Requiredness.NONE) final int a,
        @ThriftField(value=2, name="b", requiredness=Requiredness.NONE) final String b,
        @ThriftField(value=3, name="c", requiredness=Requiredness.NONE) final test.fixtures.constants.Struct1 c,
        @ThriftField(value=4, name="d", requiredness=Requiredness.NONE) final List<Integer> d
    ) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
    
    @ThriftConstructor
    protected Struct2() {
      this.a = 0;
      this.b = null;
      this.c = null;
      this.d = null;
    }
    
    public static class Builder {
        private int a;
        @ThriftField(value=1, name="a", requiredness=Requiredness.NONE)
        public Builder setA(int a) {
            this.a = a;
            return this;
        }
        private String b;
        @ThriftField(value=2, name="b", requiredness=Requiredness.NONE)
        public Builder setB(String b) {
            this.b = b;
            return this;
        }
        private test.fixtures.constants.Struct1 c;
        @ThriftField(value=3, name="c", requiredness=Requiredness.NONE)
        public Builder setC(test.fixtures.constants.Struct1 c) {
            this.c = c;
            return this;
        }
        private List<Integer> d;
        @ThriftField(value=4, name="d", requiredness=Requiredness.NONE)
        public Builder setD(List<Integer> d) {
            this.d = d;
            return this;
        }
    
        public Builder() { }
        public Builder(Struct2 other) {
            this.a = other.a;
            this.b = other.b;
            this.c = other.c;
            this.d = other.d;
        }
    
        @ThriftConstructor
        public Struct2 build() {
            return new Struct2 (
                this.a,
                this.b,
                this.c,
                this.d
            );
        }
    }
    
    private final int a;
    private final String b;
    private final test.fixtures.constants.Struct1 c;
    private final List<Integer> d;

    
    @ThriftField(value=1, name="a", requiredness=Requiredness.NONE)
    public int getA() { return a; }
        
    @ThriftField(value=2, name="b", requiredness=Requiredness.NONE)
    public String getB() { return b; }
        
    @ThriftField(value=3, name="c", requiredness=Requiredness.NONE)
    public test.fixtures.constants.Struct1 getC() { return c; }
        
    @ThriftField(value=4, name="d", requiredness=Requiredness.NONE)
    public List<Integer> getD() { return d; }
    
    @Override
    public String toString() {
        return toStringHelper(this)
            .add("a", a)
            .add("b", b)
            .add("c", c)
            .add("d", d)
            .toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        Struct2 other = (Struct2)o;
    
        return
            Objects.equals(a, other.a) &&
            Objects.equals(b, other.b) &&
            Objects.equals(c, other.c) &&
            Objects.equals(d, other.d) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            a,
            b,
            c,
            d
        });
    }
    
}
