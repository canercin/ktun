public class NodeOperations {
    /**
     * @param headNode linked list's first node
     * @param willAddNode node to add to linked list
     * @return headNode
     */
    public static Node addNode(Node headNode, Node willAddNode){
        if (headNode == null){
            headNode = willAddNode;
        }else {
            Node tempHead = headNode;
            while (tempHead.nextNode != null){
                tempHead = tempHead.nextNode;
            }
            tempHead.nextNode = willAddNode;
        }
        return headNode;
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     */
    public void adjacencyListPrinter(Node[] nodeHeads){
        for (Node node: nodeHeads) {
            while(node != null){
                if (node.nextNode != null){
                    System.out.printf("%s/%d -> ", node.cityName, node.cityNum);
                }else {
                    System.out.printf("%s/%d", node.cityName, node.cityNum);
                }
                node = node.nextNode;
            }
            System.out.println();
        }
        System.out.println("----------------------------");
        System.out.println();
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @param searchingNodeNum entry degree is the number of the search node
     * @return entry degree of related node
     */
    public int entryDegreeCounter(Node[] nodeHeads, int searchingNodeNum){
        int entryDegreeCount = 0;
        for (Node node : nodeHeads) {
            node = node.nextNode;
            while (node != null){
                if (node.cityNum == searchingNodeNum){
                    entryDegreeCount++;
                    break;
                }else {
                    node = node.nextNode;
                }
            }
        }
        return entryDegreeCount;
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @param searchingNodeNum output degree is the number of the search node
     * @return output degree of related node
     */
    public int outputDegreeCounter(Node[] nodeHeads, int searchingNodeNum){
        int outputDegreeCount = 0;
        for (Node node : nodeHeads){
            if (node.cityNum == searchingNodeNum){
                node = node.nextNode;
                while (node != null){
                    outputDegreeCount++;
                    node = node.nextNode;
                }
            }
        }
        return outputDegreeCount;
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @return edge count of graph
     */
    public int edgeCounter(Node[] nodeHeads){
        int edgeCount = 0;
        for (Node node : nodeHeads){
            while (node != null){
                edgeCount++;
                node = node.nextNode;
            }
            edgeCount--;
        }
        return edgeCount;
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @param fromWhichCity departure city number
     */
    public void whereToGo(Node[] nodeHeads, int fromWhichCity){
        Node city = whichCity(nodeHeads, fromWhichCity);
        if (city != null){
            for (Node node : nodeHeads){
                if (node.cityNum == fromWhichCity){
                    System.out.printf("%s/%d şehrinden; ", node.cityName, node.cityNum);
                    node = node.nextNode;
                    if (node != null){
                        while(node != null){
                            System.out.printf(" %s/%d", node.cityName, node.cityNum);
                            node = node.nextNode;
                            System.out.print(",");
                        }
                        System.out.println(" gidilir.\n");
                        break;
                    }else {
                        System.out.print("bir yere gidilemez. \n\n");
                    }
                }
            }
        }else {
            System.out.println("Şehir bulunamadı --HATA--\n");
        }
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @param fromWhereCity arrive city number
     */
    public void cameCityFrom(Node[] nodeHeads, int fromWhereCity){
        Node fromWhere = whichCity(nodeHeads,fromWhereCity);
        if (fromWhere != null){
            Node listHead = null;
            for (Node node : nodeHeads){
                Node rowHead = node;
                node = node.nextNode;
                while(node != null){
                    if (node.cityNum == fromWhereCity){
                        listHead = addNode(listHead, new Node(rowHead.cityName, rowHead.cityNum));
                    }
                    node = node.nextNode;
                }
            }
            ccfPrinter(listHead, fromWhere);
        }else {
            System.out.println("Şehir bulunamadı --HATA--");
        }
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @param cityNum the number of the searched city
     * @return the searched city
     */
    public static Node whichCity(Node[] nodeHeads,int cityNum){
        for (Node node : nodeHeads){
            if (node.cityNum == cityNum){
                return node;
            }
        }
        return null;
    }

    /**
     * @param listHead linked list of departure city for came city
     * @param city came of which city
     */
    public static void ccfPrinter(Node listHead, Node city){
        if (listHead != null){
            System.out.printf("%s/%d şehrine;", city.cityName, city.cityNum);
            while (listHead != null){
                System.out.printf(" %s/%d,", listHead.cityName, listHead.cityNum);
                listHead = listHead.nextNode;
            }
            System.out.print("gelinebilir.\n\n");
        }else {
            System.out.println("Bu şehrin bağlantısı yoktur.");
        }
    }

    /**
     * @param nodeHeads adjacency list of nodes in a graph
     * @param searchingNodeNum output degree is the number of the search node
     */
    public void degreePrinter(Node[] nodeHeads, int searchingNodeNum){
        int entryDegree = entryDegreeCounter(nodeHeads, searchingNodeNum);
        int outputDegree = outputDegreeCounter(nodeHeads, searchingNodeNum);
        Node city = whichCity(nodeHeads, searchingNodeNum);
        if (city != null) {
            System.out.printf("%s/%d şehrin giriş derecesi %d; çıkış derecesi %d.\n\n", city.cityName, city.cityNum, entryDegree, outputDegree);
        }else {
            System.out.println("İlgili değerli şehir bulunamadı --HATA--\n");
        }
    }
}