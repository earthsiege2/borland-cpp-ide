select Company, Sum(ItemsTotal) - Sum(AmountPaid) as AmountDue
  from customer, orders
  where Customer.CustNo = Orders.CustNo
  group by Company
